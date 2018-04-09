# BOF

LOCAL_PATH := $(abspath ..)

define walk-dir-recursive
	$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(call walk-dir-recursive, $(e)))
endef

define walk-dir
	$(wildcard $(1)) $(foreach e, $(wildcard $(1)/*), $(e))
endef

ALL_SRC_FILES = $(call walk-dir, $(LOCAL_PATH)/source)
TMP_SRC_FILES := $(filter %.c, $(ALL_SRC_FILES))

LOCAL_SRC_FILES += $(TMP_SRC_FILES)

LOCAL_MODULE := algatike

RMDIR ?=rm -Rf

XCODE_VERS := $(shell xcodebuild -sdk -version | grep "\- macOS " | cut -d "-" -f 1 | tr -d '[:space:]')
XCODE_PATH := /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
XCODE_SDK := /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_VERS)

CC := $(XCODE_PATH)/clang

ARCH := $(shell uname -m)
PLATFORM := $(shell uname -s)

LOCAL_CFLAGS += \
	-DTARGET_MACOSX=1 \
	-x c \
	-arch x86_64 \
	-mmacosx-version-min=10.8 \
	-isysroot $(XCODE_SDK) \
	-I$(LOCAL_PATH)

LOCAL_CFLAGS += \
	-std=c99
	-W \
	-Wall \
	-Wextra \
	-Wno-newline-eof \
	-pedantic \
	-fPIC \
	-fstrict-aliasing \
	-fvectorize \
	-ftree-vectorize \
	-fslp-vectorize-aggressive \
	-fvisibility=hidden \
	-funroll-loops \
	-fasm-blocks \
	-fomit-frame-pointer

LD := $(XCODE_PATH)/clang \
	-arch x86_64 \
	-isysroot $(XCODE_SDK) \
	-mmacosx-version-min=10.8 \
	-Xlinker -no_deduplicate

LOCAL_BUILDDIR := $(LOCAL_PATH)/build/$(PLATFORM)

.PHONY: all analyze clean

BUILD_FILES :=
OBJECTS_FILES :=

all: clean rule_buildir rule_template rule_objects

rule_template::
	@rm  $(LOCAL_PATH)/source/*.c
	@sh  $(LOCAL_PATH)/template/blas_@all@.sh

rule_objects::
	-@for src_file in $(LOCAL_SRC_FILES); do \
		echo "["$(PLATFORM)"-"$(ARCH)"] Compile : "$(LOCAL_MODULE)" <= "$$(basename $${src_file}); \
		$(CC) $(LOCAL_CFLAGS) -c $${src_file} -o \
			$(LOCAL_BUILDDIR)/$$(basename $${src_file%.*}).o; \
	done

rule_buildir::
	@mkdir -p $(LOCAL_BUILDDIR)
	@mkdir -p $(LOCAL_BUILDDIR)/analyzer

clean:
	@$(RMDIR) ../build
	@find .. -name ".DS_Store" -exec rm -f {} \;

# EOF