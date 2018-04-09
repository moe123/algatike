// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_math.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#include <algatike/cfortran/cfn_itypes.h>

#ifndef CFN_MATH_H
#define CFN_MATH_H

CFN_BEGIN_DECLS

#	if CFN_CC_C99

#		define CFN_DRLOG log
#		define CFN_SRLOG logf
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG CFN_SRLOG
#		else
#			define CFN_RLOG CFN_DRLOG
#		endif

#		define CFN_DRLOG2(X) log2
#		define CFN_SRLOG2(X) log2f
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG2 CFN_SRLOG2
#		else
#			define CFN_RLOG2 CFN_DRLOG2
#		endif

#		define CFN_SRABS fabsf
#		define CFN_DRABS fabs

#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RABS CFN_SRABS
#		else
#			define CFN_RABS CFN_DRABS
#		endif

#		define CFN_I32ABS(X) CFN_CAST(CFN_INTERGER32, abs(X))
#		define CFN_I64ABS(X) CFN_CAST(CFN_INTERGER64, llabs(CFN_CAST(long long, X)))

#		define CFN_DRMOD fmod
#		define CFN_SRMOD fmodf
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RMOD CFN_SRMOD
#		else
#			define CFN_RMOD CFN_DRMOD
#		endif

#	elif defined(_MSC_VER) && _MSC_VER >= 1800

#		define CFN_DRLOG log
#		define CFN_SRLOG logf
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG CFN_SRLOG
#		else
#			define CFN_RLOG CFN_DRLOG
#		endif

#		define CFN_DRLOG2(X) log2
#		define CFN_SRLOG2(X) log2f
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG2 CFN_SRLOG2
#		else
#			define CFN_RLOG2 CFN_DRLOG2
#		endif

#		define CFN_SRABS fabsf
#		define CFN_DRABS fabs
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RABS CFN_SRABS
#		else
#			define CFN_RABS CFN_DRABS
#		endif

#		define CFN_I32ABS(X) CFN_CAST(CFN_INTERGER32, abs(X))
#		define CFN_I64ABS(X) CFN_CAST(CFN_INTERGER64, _abs64(CFN_CAST(__int64, X)))

#		define CFN_DRMOD fmod
#		define CFN_SRMOD fmodf
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RMOD CFN_SRMOD
#		else
#			define CFN_RMOD CFN_DRMOD
#		endif

#	else

#		define CFN_DRLOG log
#		define CFN_SRLOG CFN_CAST(float, log(CFN_CAST(double, X)))
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG CFN_SRLOG
#		else
#			define CFN_RLOG CFN_DRLOG
#		endif

#		define CFN_DRLOG2(X) CFN_DRLOG((X)) / CFN_DRLOG((2))
#		define CFN_SRLOG2(X) CFN_SRLOG((X)) / CFN_SRLOG((2))
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RLOG2 CFN_SRLOG2
#		else
#			define CFN_RLOG2 CFN_DRLOG2
#		endif

#		define CFN_DRABS fabs
#		define CFN_SRABS(X) CFN_CAST(float, fabs(CFN_CAST(double, X)))
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RABS CFN_SRABS
#		else
#			define CFN_RABS CFN_DRABS
#		endif

#		define CFN_I32ABS(X) CFN_CAST(CFN_INTERGER32, abs(X))
#		define CFN_I64ABS(X) CFN_CAST(CFN_INTERGER64, (X == -0 ? 0 : (X < 0 ? -(X) : X)))

#		define CFN_DRMOD(NUMER, DENOM) fmod(NUMER, DENOM)
#		define CFN_SRMOD(NUMER, DENOM) CFN_CAST(float, fmod(CFN_CAST(double, NUMER), CFN_CAST(double, DENOM)))
#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_RMOD CFN_SRMOD
#		else
#			define CFN_RMOD CFN_DRMOD
#		endif

#	endif

#	define CFN_ZRABS CFN_DRABS
#	define CFN_ZRMOD CFN_DMOD

#	define CFN_DABS  CFN_DRABS
#	define CFN_DMOD  CFN_DRMOD
#	define CFN_AMOD  CFN_RMOD

#	define CFN_IMOD(A, B) ((A) % (B))

#	define CFN_RINT32(X) CFN_CAST(CFN_INTERGER32, rint(CFN_CAST(double, (X))))
#	define CFN_RINT64(X) CFN_CAST(CFN_INTERGER64, rint(CFN_CAST(double, (X))))

#	if CFN_TARGET_INTERGER_IS_INT32
#		define CFN_IABS CFN_I32ABS
#	else
#		define CFN_IABS CFN_I64ABS
#	endif

#	if CFN_TARGET_INTERGER_IS_INT32
#		define CFN_RINT CFN_RINT32
#	else
#		define CFN_RINT CFN_RINT64
#	endif

#	define CFN_DINT(X) CFN_CAST(CFN_DREAL, CFN_CAST(CFN_INTERGER64, (X)))
#	if CFN_TARGET_REAL_IS_FLOAT
#		define CFN_AINT(X) CFN_CAST(CFN_REAL, CFN_CAST(CFN_INTERGER32, (X)))
#	else
#		define CFN_AINT CFN_DINT
#	endif

#	define CFN_DNINT(X) CFN_CAST(CFN_DREAL, round(CFN_CAST(double, (X)))
#	if CFN_TARGET_REAL_IS_FLOAT
#		define CFN_ANINT(X) CFN_CAST(CFN_REAL, round(CFN_CAST(double, (X)))
#	else
#		define CFN_ANINT CFN_DNINT
#	endif

#	define CFN_IDNINT(X) CFN_CAST(CFN_INTERGER64, CFN_DNINT(X))
#	if CFN_TARGET_INTERGER_IS_INT32
#		define CFN_NINT(X) CFN_CAST(CFN_INTERGER32, CFN_ANINT(X))
#	else
#		define CFN_NINT CFN_IDNINT
#	endif

#	ifndef MIN
#		define MIN(A, B) (((A) <(B)) ? (A) : (B))
#	endif
#	ifndef MAX
#		define MAX(A, B) (((A) > (B)) ? (A) : (B))
#	endif
#	ifndef ABS
#		define ABS(X) (((X) == 0) ? 0 : ((X)< 0 ? -(X) : (X)))
#	endif

#	define CFN_MIN MIN
#	define CFN_MAX MAX
#	define CFN_ABS ABS

#	define CFN_IMAX  CFN_MAX

#	define CFN_NAN NAN
#	define CFN_INF INF
#	define CFN_ISINF isinf
#	define CFN_ISNAN isnan

#	define CFN_SRSIGN(A, B) ((B) >= 0) ? CFN_SRABS(A) : -(CFN_SRABS(A))
#	define CFN_DRSIGN(A, B) ((B) >= 0) ? CFN_DRABS(A) : -(CFN_DRABS(A))
#	define CFN_ZRSIGN(A, B) CFN_DRSIGN(A, B)

#	define CFN_ISIGN(A, B) ((B) >= 0) ? CFN_ABS(A)  : -(CFN_ABS(A))
#	define CFN_RSIGN(A, B) ((B) >= 0) ? CFN_RABS(A) : -(CFN_RABS(A))
#	define CFN_DSIGN(A, B) CFN_DRSIGN(A, B)

#	define CFN_DIM(X, Y) (X) > (Y) ? ((X) - (Y)) : 0

CFN_END_DECLS

#endif /* !CFN_MATH_H */

/* EOF */