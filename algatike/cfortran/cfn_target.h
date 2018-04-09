// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_target.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#ifndef CFN_TARGET_H
#define CFN_TARGET_H

#	define CFN_DEBUG 1

#	ifndef CFN_TARGET_REAL_IS_FLOAT
#		define CFN_TARGET_REAL_IS_FLOAT     1
#	endif
#	ifndef CFN_TARGET_INTERGER_IS_INT32
#		define CFN_TARGET_INTERGER_IS_INT32     1
#	endif

#	ifdef __cplusplus
#		define CFN_BEGIN_DECLS extern "C" {
#		define CFN_END_DECLS }
#	else
#		define CFN_BEGIN_DECLS
#		define CFN_END_DECLS
#	endif

#	if defined(_MSC_VER)
#		define CFN_CC_MSC 1
#	elif defined(__clang__) || defined(__llvm__)
#		define CFN_CC_CLANG 1
#	elif defined(__GNUC__)
#		define CFN_CC_GCC 1
#	endif

#	if !defined(CFN_ALWAYS_INLINE)
#		if CFN_CC_MSC
#			define CFN_ALWAYS_INLINE __forceinline
#		elif (((CFN_CC_GCC && __GNUC__ >= 4) || CFN_CC_CLANG))
#			define CFN_ALWAYS_INLINE __inline__ __attribute__((always_inline))
#		else
#			define CFN_ALWAYS_INLINE inline
#		endif
#	endif

#	if !defined(CFN_NEVER_INLINE)
#		if CFN_CC_MSC
#			define CFN_NEVER_INLINE __declspec(noinline)
#		elif (((CFN_CC_GCC && __GNUC__ >= 4) || CFN_CC_CLANG))
#			define CFN_NEVER_INLINE __attribute__((noinline))
#		else
#			define CFN_NEVER_INLINE
#		endif
#	endif

#	if !defined(CFN_VOLATILE)
#		define CFN_VOLATILE volatile
#	endif

#	define CFN_STATIC               static
#	define CFN_INLINE               inline
#	define CFN_STATIC_INLINE        CFN_STATIC CFN_INLINE
#	define CFN_STATIC_ALWAYS_INLINE CFN_STATIC CFN_ALWAYS_INLINE

CFN_BEGIN_DECLS

#	include <stddef.h>
#	include <stdio.h>
#	include <stdarg.h>
#	include <string.h>
#	include <math.h>
#	include <signal.h>
#	include <inttypes.h>
#	if defined(__STDC__)
#		define CFN_CC_C89 1
#		if defined(__STDC_VERSION__)
#			define CFN_CC_C90 1
#			if (__STDC_VERSION__ >= 199409L)
#				define CFN_CC_C94 1
#			endif
#			if (__STDC_VERSION__ >= 199901L)
#				include <tgmath.h>
#				include <complex.h>
#				include <inttypes.h>
#				include <stdbool.h>
#				include <stdint.h>
#				define CFN_CC_C99 1
#			endif
#			if (__STDC_VERSION__ >= 201112L)
#				define CFN_CC_C11 1
#			endif
#		endif
#	endif

#	if !CFN_CC_C99 && defined(_MSC_VER) && (_MSC_VER >= 1600)
#		include <inttypes.h>
#		include <stdint.h>
#	endif

#	if !CFN_CC_C99 && defined(_MSC_VER) && (_MSC_VER > 1800)
#		include <stdbool.h>
#	endif

#	define CFN_PPCAT_NX_2(A, B) A ## B
#	define CFN_PPCAT_NX_3(A, B, C) A ## B ## C
#	define CFN_PPCAT_NX_7(A, B, C, D, E, F, G) \
	A ## B ## C ## D ## E ## F ## G

#	define CFN_PPCAT_2(A, B) CFN_PPCAT_NX_2(A, B)
#	define CFN_PPCAT_3(A, B, C) CFN_PPCAT_NX_3(A, B, C)
#	define CFN_PPCAT_7(A, B, C, D, E, F, G) \
	CFN_PPCAT_NX_7(A, B, C, D, E, F, G)


#	define CFN_PTR_TO(ID)     *  ID
#	define CFN_PTR_PTR_TO(ID) ** ID
#	define CFN_PTR_DEREF(PTR) *  PTR
#	define CFN_CAST(TYPE, N) (TYPE)N

#	define CFN_CERR(...) fprintf(stderr, __VA_ARGS__)
#	define CFN_STOP      raise(SIGILL)

#	define CFN_VECTOR_DECL(TYPE, NAME, N) \
	(TYPE) NAME[N]

#	define CFN_CMATRIX_DECL(TYPE, NAME, M, N) \
	(TYPE) NAME[M][N]

#	define CFN_VECTOR_NEW(TYPE, NAME, N) \
	(TYPE) * NAME = ((TYPE) *)malloc(N * sizeof((TYPE)))

#	define CFN_MATRIX_NEW(TYPE, NAME, N, M) \
	(TYPE) ** NAME = ((TYPE) **)malloc(M * sizeof((TYPE) *)); \
	do { \
		for (size_t cfn_idx = 0; cfn_idx < N; cfn_idx++) { \
			NAME[cfn_idx] = ((TYPE) *)malloc(N * sizeof((TYPE))); \
		} \
	} while (0)

#	define CFN_SMATRIX_NEW(TYPE, NAME, N, M) \
	(TYPE) * NAME = ((TYPE) *)malloc(N * M * sizeof((TYPE)))

#	define CFN_VECTOR_DEL(ADDR) \
	free(ADDR)

#	define CFN_MATRIX_DEL(NAME, M) \
	do { \
		for(size_t cfn_idx = 0; cfn_idx < M; cfn_idx++) { \
			free(NAME[cfn_idx]); \
		} \
		free(NAME); \
		NAME = NULL; \
	} while (0)

#	define CFN_EXTERNAL  extern
#	define CFN_VOID      void

#	define CFN_D1D(ID)      CFN_PTR_TO     (ID)
#	define CFN_D2D(ID)      CFN_PTR_PTR_TO (ID)
#	define CFN_D2D_A(ID, N) (*((ID)))[N]
#	define CFN_ADDR(ID)     CFN_PTR_TO     (ID)
#	define CFN_ADRF(ID)     CFN_PTR_DEREF((ID))

CFN_END_DECLS

#endif /* !CFN_TARGET_H */

/* EOF */