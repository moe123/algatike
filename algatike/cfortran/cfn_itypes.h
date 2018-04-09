// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_itypes.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#include <algatike/cfortran/cfn_target.h>

#ifndef CFN_TYPES_H
#define CFN_TYPES_H

CFN_BEGIN_DECLS

#	if CFN_CC_C99
#		define CFN_LOGICAL    bool
#		define CFN_TRUE       true
#		define CFN_FALSE      false
#		define CFN_INTEGER8   int8_t
#		define CFN_INTEGER16  int16_t
#		define CFN_INTEGER32  int32_t
#		define CFN_INTEGER64  int64_t
#		define CFN_UINTEGER8  uint8_t
#		define CFN_UINTEGER16 uint16_t
#		define CFN_UINTEGER32 uint32_t
#		define CFN_UINTEGER64 uint64_t
#	elif defined(_MSC_VER)
#		if (_MSC_VER < 1800)
#			define CFN_LOGICAL     BOOL
#			define CFN_TRUE        TRUE
#			define CFN_FALSE       FALSE
#		endif
#		if (_MSC_VER < 1600)
#			define CFN_INTEGER8   __int8
#			define CFN_INTEGER16  __int16
#			define CFN_INTEGER32  __int32
#			define CFN_INTEGER64  __int64
#			define CFN_UINTEGER8  unsigned __int8
#			define CFN_UINTEGER16 unsigned __int16
#			define CFN_UINTEGER32 unsigned __int32
#			define CFN_UINTEGER64 unsigned __int64
#		else
#			define CFN_INTEGER8   int8_t
#			define CFN_INTEGER16  int16_t
#			define CFN_INTEGER32  int32_t
#			define CFN_INTEGER64  int64_t
#			define CFN_UINTEGER8  uint8_t
#			define CFN_UINTEGER16 uint16_t
#			define CFN_UINTEGER32 uint32_t
#			define CFN_UINTEGER64 uint64_t
#		endif
#	else
#		define CFN_LOGICAL    int
#		define CFN_TRUE       1
#		define CFN_FALSE      0
#		define CFN_INTEGER8   char
#		define CFN_INTEGER16  short
#		define CFN_INTEGER32  int
#		define CFN_INTEGER64  long long
#		define CFN_UINTEGER8  unsigned char
#		define CFN_UINTEGER16 unsigned short
#		define CFN_UINTEGER32 unsigned int
#		define CFN_UINTEGER64 unsigned long long
#	endif

#	if CFN_TARGET_INTERGER_IS_INT32
#		define CFN_INTEGER  CFN_INTEGER32
#		define CFN_UINTEGER CFN_UINTEGER32
#	else
#		define CFN_INTEGER  CFN_INTEGER64
#		define CFN_UINTEGER CFN_UINTEGER64
#	endif

#	define CFN_REAL32  float
#	define CFN_REAL64  double

#	if CFN_TARGET_REAL_IS_FLOAT
#		define CFN_REAL CFN_REAL32
#	else
#		define CFN_REAL CFN_REAL64
#	endif

#	define CFN_SREAL  CFN_REAL32
#	define CFN_DREAL  CFN_REAL64
#	define CFN_ZREAL  CFN_REAL64

CFN_END_DECLS

#endif /* !CFN_TYPES_H */

/* EOF */