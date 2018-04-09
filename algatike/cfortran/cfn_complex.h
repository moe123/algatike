// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_complex.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>

#ifndef CFN_COMPLEX_H
#define CFN_COMPLEX_H

CFN_BEGIN_DECLS

#	if CFN_CC_C99
#		define CFN_CPLXR(Z__) __real__ Z__
#		define CFN_CPLXI(Z__) __imag__ Z__

#		define CFN_SCREAL(Z__) crealf(Z__)
#		define CFN_SCIMAG(Z__) cimagf(Z__)
#		define CFN_SCABS(Z__)  cabsf(Z__)
#		define CFN_SCONJG(Z__) conjf(Z__)
#		define CFN_SCSQRT(Z__) csqrtf(Z__)

		typedef float  _Complex CFN_SCOMPLEX CFN_EOI

#		define CFN_DCREAL(Z__) creal(Z__)
#		define CFN_DCIMAG(Z__) cimag(Z__)
#		define CFN_DCABS(Z__)  cabs(Z__)
#		define CFN_DCONJG(Z__) conj(Z__)
#		define CFN_DCSQRT(Z__) csqrt(Z__)

		typedef double _Complex CFN_DCOMPLEX CFN_EOI

#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_COMPLEX CFN_SCOMPLEX
#			define CFN_CREAL CFN_SCREAL
#			define CFN_CIMAG CFN_SCIMAG
#			define CFN_CABS  CFN_SCABS
#			define CFN_CONJG CFN_SCONJG
#			define CFN_CSQRT CFN_SCSQRT
#		else
#			define CFN_COMPLEX CFN_DCOMPLEX
#			define CFN_CREAL CFN_DCREAL
#			define CFN_CIMAG CFN_DCIMAG
#			define CFN_CABS  CFN_DCABS
#			define CFN_CONJG CFN_DCONJG
#			define CFN_CSQRT CFN_DCSQRT
#		endif

#		define CFN_ZCOMPLEX CFN_DCOMPLEX

#		define CFN_CPLXRI(CN, CR, CI) \
			CFN_CPLXR(CN) = CR CFN_EOI \
			CFN_CPLXI(CN) = CI

#		define CFN_SCMPLX_DECL(CN, CR, CI) \
			CFN_SCOMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#		define CFN_DCMPLX_DECL(CN, CR, CI) \
			CFN_DCOMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#		define CFN_ZCMPLX_DECL CFN_DCMPLX_DECL

#		define CFN_CMPLX_DECL(CN, CR, CI) \
			CFN_COMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#	elif defined(_MSC_VER) && (_MSC_VER > 1800)

#		define CFN_CPLXR(Z__) // extension available ?
#		define CFN_CPLXI(Z__) // extension available ?

#		define CFN_SCREAL(Z__) crealf(Z__)
#		define CFN_SCIMAG(Z__) cimagf(Z__)
#		define CFN_SCABS(Z__)  cabsf(Z__)
#		define CFN_SCONJG(Z__) conjf(Z__)
#		define CFN_SCSQRT(Z__) csqrtf(Z__)

		typedef _Fcomplex CFN_SCOMPLEX CFN_EOI

#		define CFN_DCREAL(Z__) creal(Z__)
#		define CFN_DCIMAG(Z__) cimag(Z__)
#		define CFN_DCABS(Z__)  cabs(Z__)
#		define CFN_DCONJG(Z__) conj(Z__)
#		define CFN_DCSQRT(Z__) csqrt(Z__)

		typedef _Dcomplex CFN_DCOMPLEX CFN_EOI

#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_COMPLEX CFN_SCOMPLEX
#			define CFN_CREAL CFN_SCREAL
#			define CFN_CIMAG CFN_SCIMAG
#			define CFN_CABS  CFN_SCABS
#			define CFN_CONJG CFN_SCONJG
#			define CFN_CSQRT CFN_SCSQRT
#		else
#			define CFN_COMPLEX CFN_DCOMPLEX
#			define CFN_CREAL CFN_DCREAL
#			define CFN_CIMAG CFN_DCIMAG
#			define CFN_CABS  CFN_DCABS
#			define CFN_CONJG CFN_DCONJG
#			define CFN_CSQRT CFN_DCSQRT
#		endif

#		define CFN_ZCOMPLEX CFN_DCOMPLEX

#		define CFN_CPLXRI(CN, CR, CI) \
			CN = { (CR), (CI) }

#		define CFN_SCMPLX_DECL(CN, CR, CI) \
			CFN_SCOMPLEX CN = { (CR), (CI) }

#		define CFN_DCMPLX_DECL(CN, CR, CI) \
			CFN_DCOMPLEX CN = { (CR), (CI) }

#		define CFN_ZCMPLX_DECL CFN_DCMPLX_DECL

#		define CFN_CMPLX_DECL(CN, CR, CI) \
			CFN_COMPLEX CN = { (CR), (CI) }

#	else
		struct CFN_SCOMPLEX { CFN_SREAL _M_real; CFN_SREAL _M_imag; };
		typedef struct CFN_SCOMPLEX CFN_SCOMPLEX;

		struct CFN_DCOMPLEX { CFN_DREAL _M_real CFN_EOI CFN_DREAL _M_imag CFN_EOI };
		typedef struct CFN_DCOMPLEX CFN_DCOMPLEX;

#		define CFN_CPLXR(Z__) Z__._M_real
#		define CFN_CPLXI(Z__) Z__._M_imag

#		define CFN_SCREAL(Z__) CFN_CPLXR(Z__)
#		define CFN_SCIMAG(Z__) CFN_CPLXI(Z__)

#		define CFN_DCREAL(Z__) CFN_CPLXR(Z__)
#		define CFN_DCIMAG(Z__) CFN_CPLXI(Z__)

#		define CFN_CREAL(Z__) CFN_CPLXR(Z__)
#		define CFN_CIMAG(Z__) CFN_CPLXI(Z__)

#		define CFN_SCABS(Z__) \
			sqrtf( \
				CFN_SCREAL(Z__) * CFN_SCREAL(Z__) + \
				CFN_SCIMAG(Z__) * CFN_SCIMAG(Z__) \
			)

#		define CFN_DCABS(Z__) \
			sqrt( \
				CFN_DCREAL(Z__) * CFN_DCREAL(Z__) + \
				CFN_DCIMAG(Z__) * CFN_DCIMAG(Z__) \
			)

#		if CFN_TARGET_REAL_IS_FLOAT
#			define CFN_COMPLEX CFN_SCOMPLEX
#			define CFN_CABS    CFN_SCABS
#		else
#			define CFN_COMPLEX CFN_DCOMPLEX
#			define CFN_CABS    CFN_DCABS
#		endif

		CFN_INTRINSIC(SCOMPLEX, SCONJG,
		(
			CFN_SCOMPLEX Z
		))
			CFN_SCOMPLEX SCONJG CFN_EOI
			CFN_CPLXR(SCONJG) = CFN_SCREAL(Z) CFN_EOI
			CFN_CPLXI(SCONJG) = -CFN_SCIMAG(Z) CFN_EOI

			CFN_RETURN SCONJG CFN_EOI
			CFN_END

		CFN_INTRINSIC(DCOMPLEX, DCONJG,
		(
			CFN_DCOMPLEX Z
		))
			CFN_DCOMPLEX DCONJG CFN_EOI
			CFN_CPLXR(DCONJG) = CFN_DCREAL(Z) CFN_EOI
			CFN_CPLXI(DCONJG) = -CFN_DCIMAG(Z) CFN_EOI

			CFN_RETURN DCONJG CFN_EOI
			CFN_END

		CFN_INTRINSIC(COMPLEX, CONJG,
		(
			CFN_COMPLEX Z
		))
			CFN_COMPLEX CONJG CFN_EOI
			CFN_CPLXR(CONJG) = CFN_CREAL(Z) CFN_EOI
			CFN_CPLXI(CONJG) = -CFN_CIMAG(Z) CFN_EOI

			CFN_RETURN CONJG CFN_EOI
			CFN_END

		CFN_INTRINSIC(SCOMPLEX, SCSQRT,
		(
			CFN_SCOMPLEX Z
		))
			// TODO
			CFN_RETURN Z CFN_EOI
			CFN_END

		CFN_INTRINSIC(DCOMPLEX, DCSQRT,
		(
			CFN_DCOMPLEX Z
		))
			// TODO
			CFN_RETURN Z CFN_EOI
			CFN_END

		CFN_INTRINSIC(COMPLEX, CSQRT,
		(
			CFN_COMPLEX Z
		))
			// TODO
			CFN_RETURN Z CFN_EOI
			CFN_END

#		define CFN_ZCOMPLEX CFN_DCOMPLEX

#		define CFN_CPLXRI(CN, CR, CI) \
			CFN_CPLXR(CN) = CR CFN_EOI \
			CFN_CPLXI(CN) = CI

#		define CFN_SCMPLX_DECL(CN, CR, CI) \
			CFN_SCOMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#		define CFN_DCMPLX_DECL(CN, CR, CI) \
			CFN_DCOMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#		define CFN_ZCMPLX_DECL CFN_DCMPLX_DECL

#		define CFN_CMPLX_DECL(CN, CR, CI) \
			CFN_COMPLEX CN CFN_EOI \
			CFN_CPLXRI(CN, CR, CI)

#	endif

#	define CFN_CDABS    CFN_DCABS
#	define CFN_ZABS     CFN_DCABS

#	define CFN_ZCREAL   CFN_DCREAL
#	define CFN_ZCIMAG   CFN_DCIMAG
#	define CFN_ZCABS    CFN_DCABS
#	define CFN_ZCONJG   CFN_DCONJG
#	define CFN_ZCSQRT   CFN_DCSQRT

CFN_INTRINSIC(SCOMPLEX, SCMPLX,
(
	  CFN_SREAL CR
	, CFN_SREAL CI
))
	CFN_SCMPLX_DECL(SCMPLX, CR, CI) CFN_EOI

	CFN_RETURN SCMPLX CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCMPLX,
(
	  CFN_DREAL CR
	, CFN_DREAL CI
))
	CFN_DCMPLX_DECL(DCMPLX, CR, CI) CFN_EOI

	CFN_RETURN DCMPLX CFN_EOI
	CFN_END

#	define CFN_ZCMPLX CFN_DCMPLX

CFN_INTRINSIC(COMPLEX, CMPLX,
(
	  CFN_REAL CR
	, CFN_REAL CI
))
	CFN_CMPLX_DECL(CMPLX, CR, CI) CFN_EOI

	CFN_RETURN CMPLX CFN_EOI	
	CFN_END

#pragma mark -

CFN_INTRINSIC(LOGICAL, SCEQ,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_RETURN (CFN_SCREAL(Z1) == CFN_SCREAL(Z2) && CFN_SCIMAG(Z1) == CFN_SCIMAG(Z2)) CFN_EOI
	CFN_END

CFN_INTRINSIC(LOGICAL, SCNE,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_RETURN CFN_NOT(CFN_SCEQ(Z1, Z2)) CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(LOGICAL, DCEQ,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_RETURN (CFN_DCREAL(Z1) == CFN_DCREAL(Z2) && CFN_DCIMAG(Z1) == CFN_DCIMAG(Z2)) CFN_EOI
	CFN_END

CFN_INTRINSIC(LOGICAL, DCNE,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_RETURN CFN_NOT(CFN_DCEQ(Z1, Z2)) CFN_EOI
	CFN_END

#pragma mark -
	
CFN_INTRINSIC(LOGICAL, ZCEQ,
(
	  CFN_ZCOMPLEX Z1
	, CFN_ZCOMPLEX Z2
))
	CFN_RETURN (CFN_ZCREAL(Z1) == CFN_ZCREAL(Z2) && CFN_ZCIMAG(Z1) == CFN_ZCIMAG(Z2)) CFN_EOI
	CFN_END

CFN_INTRINSIC(LOGICAL, ZCNE,
(
	  CFN_ZCOMPLEX Z1
	, CFN_ZCOMPLEX Z2
))
	CFN_RETURN CFN_NOT(CFN_ZCEQ(Z1, Z2)) CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(LOGICAL, CEQ,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))
	CFN_RETURN (CFN_CREAL(Z1) == CFN_CREAL(Z2) && CFN_CIMAG(Z1) == CFN_CIMAG(Z2)) CFN_EOI
	CFN_END

CFN_INTRINSIC(LOGICAL, CNE,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))
	CFN_RETURN CFN_NOT(CFN_CEQ(Z1, Z2)) CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(SCOMPLEX, SCADDMUL,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
	, CFN_SREAL X2
))
	CFN_SCOMPLEX SCADDMUL CFN_EOI
	CFN_SREAL R1, R2, I1, I2 CFN_EOI
	
	R1 = CFN_SCREAL(Z1) CFN_EOI
	R2 = CFN_SCREAL(Z2) CFN_EOI
	I1 = CFN_SCIMAG(Z1) CFN_EOI
	I2 = CFN_SCIMAG(Z2) CFN_EOI

	CFN_CPLXRI(SCADDMUL
		, R1 + X2 * R2
		, I1 + X2 * I2
	) CFN_EOI

	CFN_RETURN SCADDMUL CFN_EOI
	CFN_END

CFN_INTRINSIC(SCOMPLEX, DCADDMUL,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
	, CFN_DREAL X2
))
	CFN_DCOMPLEX DCADDMUL CFN_EOI
	CFN_DREAL R1, R2, I1, I2 CFN_EOI
	
	R1 = CFN_DCREAL(Z1) CFN_EOI
	R2 = CFN_DCREAL(Z2) CFN_EOI
	I1 = CFN_DCIMAG(Z1) CFN_EOI
	I2 = CFN_DCIMAG(Z2) CFN_EOI

	CFN_CPLXRI(DCADDMUL
		, R1 + X2 * R2
		, I1 + X2 * I2
	) CFN_EOI

	CFN_RETURN DCADDMUL CFN_EOI
	CFN_END

#	define CFN_ZCADDMUL CFN_DCADDMUL

CFN_INTRINSIC(SCOMPLEX, CADDMUL,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
	, CFN_REAL X2
))
	CFN_COMPLEX CADDMUL CFN_EOI
	CFN_REAL R1, R2, I1, I2 CFN_EOI
	
	R1 = CFN_CREAL(Z1) CFN_EOI
	R2 = CFN_CREAL(Z2) CFN_EOI
	I1 = CFN_CIMAG(Z1) CFN_EOI
	I2 = CFN_CIMAG(Z2) CFN_EOI

	CFN_CPLXRI(CADDMUL
		, R1 + X2 * R2
		, I1 + X2 * I2
	) CFN_EOI

	CFN_RETURN CADDMUL CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(SREAL, SCNORM,
(
	CFN_SCOMPLEX Z
))
	CFN_SREAL R0, I0 CFN_EOI

	R0 = CFN_SCREAL(Z) CFN_EOI
	I0 = CFN_SCIMAG(Z) CFN_EOI

	CFN_IF (CFN_ISINF(R0)) CFN_RETURN CFN_SRABS(R0) CFN_EOI
	CFN_IF (CFN_ISINF(I0)) CFN_RETURN CFN_SRABS(I0) CFN_EOI

	CFN_RETURN R0 * R0 + I0 * I0 CFN_EOI
	CFN_END

CFN_INTRINSIC(DREAL, DCNORM,
(
	CFN_DCOMPLEX Z
))
	CFN_DREAL R0, I0 CFN_EOI

	R0 = CFN_DCREAL(Z) CFN_EOI
	I0 = CFN_DCIMAG(Z) CFN_EOI

	CFN_IF (CFN_ISINF(R0)) CFN_RETURN CFN_DRABS(R0) CFN_EOI
	CFN_IF (CFN_ISINF(I0)) CFN_RETURN CFN_DRABS(I0) CFN_EOI

	CFN_RETURN R0 * R0 + I0 * I0 CFN_EOI
	CFN_END

#	define CFN_ZCNORM CFN_DCNORM

CFN_INTRINSIC(REAL, CNORM,
(
	CFN_COMPLEX Z
))
	CFN_REAL R0, I0 CFN_EOI

	R0 = CFN_CREAL(Z) CFN_EOI
	I0 = CFN_CIMAG(Z) CFN_EOI

	CFN_IF (CFN_ISINF(R0)) CFN_RETURN CFN_RABS(R0) CFN_EOI
	CFN_IF (CFN_ISINF(I0)) CFN_RETURN CFN_RABS(I0) CFN_EOI

	CFN_RETURN R0 * R0 + I0 * I0 CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(SCOMPLEX, SCRECIP,
(
	CFN_SCOMPLEX Z
))
	CFN_SCOMPLEX SCRECIP CFN_EOI
	CFN_SREAL N CFN_EOI

	N = 1 / CFN_SCNORM(Z) CFN_EOI

	CFN_CPLXRI(SCRECIP
		, N * CFN_SCREAL(Z)
		, N * CFN_SCIMAG(Z)
	) CFN_EOI

	CFN_RETURN SCRECIP CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCRECIP,
(
	CFN_DCOMPLEX Z
))
	CFN_DCOMPLEX DCRECIP CFN_EOI
	CFN_DREAL N CFN_EOI

	N = 1 / CFN_DCNORM(Z) CFN_EOI

	CFN_CPLXRI(DCRECIP
		, N * CFN_DCREAL(Z)
		, N * CFN_DCIMAG(Z)
	) CFN_EOI

	CFN_RETURN DCRECIP CFN_EOI
	CFN_END

#	define CFN_ZCRECIP CFN_DCRECIP

CFN_INTRINSIC(COMPLEX, CRECIP,
(
	CFN_COMPLEX Z
))
	CFN_COMPLEX CRECIP CFN_EOI
	CFN_REAL N CFN_EOI

	N = 1 / CFN_CNORM(Z) CFN_EOI

	CFN_CPLXRI(CRECIP
		, N * CFN_CREAL(Z)
		, N * CFN_CIMAG(Z)
	) CFN_EOI

	CFN_RETURN CRECIP CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(SCOMPLEX, SCNEG,
(
	CFN_SCOMPLEX Z
))
	CFN_SCMPLX_DECL(SCNEG, -CFN_SCREAL(Z), -CFN_SCIMAG(Z)) CFN_EOI

	CFN_RETURN SCNEG CFN_EOI
	CFN_END

CFN_INTRINSIC(SCOMPLEX, SCADD,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_SCOMPLEX SCADD CFN_EOI

	CFN_CPLXRI(SCADD
		, CFN_SCREAL(Z1) + CFN_SCREAL(Z2)
		, CFN_SCIMAG(Z1) + CFN_SCIMAG(Z2)
	) CFN_EOI

	CFN_RETURN SCADD CFN_EOI
	CFN_END

CFN_INTRINSIC(SCOMPLEX, SCSUB,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_SCOMPLEX SCSUB CFN_EOI

	CFN_CPLXRI(SCSUB
		, CFN_SCREAL(Z1) - CFN_SCREAL(Z2)
		, CFN_SCIMAG(Z1) - CFN_SCIMAG(Z2)
	) CFN_EOI

	CFN_RETURN SCSUB CFN_EOI
	CFN_END

CFN_INTRINSIC(SCOMPLEX, SCMUL,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_SCOMPLEX SCMUL CFN_EOI
	CFN_SREAL R1, R2, I1, I2 CFN_EOI

	R1 = CFN_SCREAL(Z1) CFN_EOI
	R2 = CFN_SCREAL(Z2) CFN_EOI
	I1 = CFN_SCIMAG(Z1) CFN_EOI
	I2 = CFN_SCIMAG(Z2) CFN_EOI

	CFN_CPLXRI(SCMUL
		, (R1 * R2) - (I1 * I2)
		, (R1 * I2) + (R2 * I1)
	) CFN_EOI

	CFN_RETURN SCMUL CFN_EOI
	CFN_END

CFN_INTRINSIC(SCOMPLEX, SCDIV,
(
	  CFN_SCOMPLEX Z1
	, CFN_SCOMPLEX Z2
))
	CFN_SCOMPLEX SCDIV CFN_EOI
	CFN_SREAL D;

	D = CFN_SCREAL(Z2) * CFN_SCREAL(Z2) + CFN_SCIMAG(Z2) * CFN_SCIMAG(Z2) CFN_EOI

	CFN_IF (D CFN_EQ 0.0)
	CFN_THEN
		CFN_CPLXRI(SCDIV
			, CFN_NAN
			, CFN_NAN
		) CFN_EOI
	CFN_ELSE
		CFN_CPLXRI(SCDIV
			, (CFN_SCREAL(Z1) * CFN_SCREAL(Z2) + CFN_SCIMAG(Z1) * CFN_SCIMAG(Z2)) / D
			, (CFN_SCIMAG(Z1) * CFN_SCREAL(Z2) - CFN_SCREAL(Z1) * CFN_SCIMAG(Z2)) / D
		) CFN_EOI
	CFN_END_IF

	CFN_RETURN SCDIV CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(DCOMPLEX, DCNEG,
(
	CFN_DCOMPLEX Z
))
	CFN_DCMPLX_DECL(DCNEG, -CFN_DCREAL(Z), -CFN_DCIMAG(Z)) CFN_EOI

	CFN_RETURN DCNEG CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCADD,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_DCOMPLEX DCADD CFN_EOI

	CFN_CPLXRI(DCADD
		, CFN_DCREAL(Z1) + CFN_DCREAL(Z2)
		, CFN_DCIMAG(Z1) + CFN_DCIMAG(Z2)
	) CFN_EOI

	CFN_RETURN DCADD CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCSUB,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_DCOMPLEX DCSUB CFN_EOI

	CFN_CPLXRI(DCSUB
		, CFN_DCREAL(Z1) - CFN_DCREAL(Z2)
		, CFN_DCIMAG(Z1) - CFN_DCIMAG(Z2)
	) CFN_EOI

	CFN_RETURN DCSUB CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCMUL,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_DCOMPLEX DCMUL CFN_EOI
	CFN_DREAL R1, R2, I1, I2 CFN_EOI

	R1 = CFN_DCREAL(Z1) CFN_EOI
	R2 = CFN_DCREAL(Z2) CFN_EOI
	I1 = CFN_DCIMAG(Z1) CFN_EOI
	I2 = CFN_DCIMAG(Z2) CFN_EOI

	CFN_CPLXRI(DCMUL
		, (R1 * R2) - (I1 * I2)
		, (R1 * I2) + (R2 * I1)
	) CFN_EOI

	CFN_RETURN DCMUL CFN_EOI
	CFN_END

CFN_INTRINSIC(DCOMPLEX, DCDIV,
(
	  CFN_DCOMPLEX Z1
	, CFN_DCOMPLEX Z2
))
	CFN_DCOMPLEX DCDIV CFN_EOI
	CFN_DREAL D;

	D = CFN_DCREAL(Z2) * CFN_DCREAL(Z2) + CFN_DCIMAG(Z2) * CFN_DCIMAG(Z2) CFN_EOI

	CFN_IF (D CFN_EQ 0.0)
	CFN_THEN
		CFN_CPLXRI(DCDIV
			, CFN_NAN
			, CFN_NAN
		) CFN_EOI
	CFN_ELSE
		CFN_CPLXRI(DCDIV
			, (CFN_DCREAL(Z1) * CFN_DCREAL(Z2) + CFN_DCIMAG(Z1) * CFN_DCIMAG(Z2)) / D
			, (CFN_DCIMAG(Z1) * CFN_DCREAL(Z2) - CFN_DCREAL(Z1) * CFN_DCIMAG(Z2)) / D
		) CFN_EOI
	CFN_END_IF

	CFN_RETURN DCDIV CFN_EOI
	CFN_END

#pragma mark -

#	define CFN_ZCNEG CFN_DCNEG
#	define CFN_ZCADD CFN_DCADD
#	define CFN_ZCSUB CFN_DCSUB
#	define CFN_ZCMUL CFN_DCMUL
#	define CFN_ZCDIV CFN_DCDIV

#pragma mark -

CFN_INTRINSIC(COMPLEX, CNEG,
(
	CFN_COMPLEX Z
))
	CFN_CMPLX_DECL(CNEG, -CFN_CREAL(Z), -CFN_CIMAG(Z)) CFN_EOI

	CFN_RETURN CNEG CFN_EOI
	CFN_END

CFN_INTRINSIC(COMPLEX, CADD,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))

	CFN_COMPLEX CADD CFN_EOI

	CFN_CPLXRI(CADD
		, CFN_CREAL(Z1) + CFN_CREAL(Z2)
		, CFN_CIMAG(Z1) + CFN_CIMAG(Z2)
	) CFN_EOI

	CFN_RETURN CADD CFN_EOI
	CFN_END

CFN_INTRINSIC(COMPLEX, CSUB,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))
	CFN_COMPLEX CSUB CFN_EOI

	CFN_CPLXRI(CSUB
		, CFN_CREAL(Z1) - CFN_CREAL(Z2)
		, CFN_CIMAG(Z1) - CFN_CIMAG(Z2)
	) CFN_EOI

	CFN_RETURN CSUB CFN_EOI
	CFN_END

CFN_INTRINSIC(COMPLEX, CMUL,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))
	CFN_COMPLEX CMUL CFN_EOI
	CFN_REAL R1, R2, I1, I2 CFN_EOI

	R1 = CFN_CREAL(Z1) CFN_EOI
	R2 = CFN_CREAL(Z2) CFN_EOI
	I1 = CFN_CIMAG(Z1) CFN_EOI
	I2 = CFN_CIMAG(Z2) CFN_EOI

	CFN_CPLXRI(CMUL
		, (R1 * R2) - (I1 * I2)
		, (R1 * I2) + (R2 * I1)
	) CFN_EOI

	CFN_RETURN CMUL CFN_EOI
	CFN_END

CFN_INTRINSIC(COMPLEX, CDIV,
(
	  CFN_COMPLEX Z1
	, CFN_COMPLEX Z2
))
	CFN_COMPLEX CDIV CFN_EOI
	CFN_REAL D;

	D = CFN_CREAL(Z2) * CFN_CREAL(Z2) + CFN_CIMAG(Z2) * CFN_CIMAG(Z2) CFN_EOI

	CFN_IF (D CFN_EQ 0.0) CFN_THEN
		CFN_CPLXRI(CDIV
			, CFN_NAN
			, CFN_NAN
		) CFN_EOI
	CFN_ELSE
		CFN_CPLXRI(CDIV
			, (CFN_CREAL(Z1) * CFN_CREAL(Z2) + CFN_CIMAG(Z1) * CFN_CIMAG(Z2)) / D
			, (CFN_CIMAG(Z1) * CFN_CREAL(Z2) - CFN_CREAL(Z1) * CFN_CIMAG(Z2)) / D
		) CFN_EOI
	CFN_END_IF

	CFN_RETURN CDIV CFN_EOI
	CFN_END

#pragma mark -

CFN_INTRINSIC(INTEGER, SCSQUAD,
(
	  CFN_SREAL A
	, CFN_SREAL B
	, CFN_SREAL C
	, CFN_INTEGER INCR
	, CFN_SCOMPLEX CFN_D1D(CR)
))
	CFN_SCMPLX_DECL(C1, -B, 0) CFN_EOI
	CFN_SCMPLX_DECL(C2, (B * B - 4 * A * C), 0) CFN_EOI
	CFN_SCMPLX_DECL(C3, (2 * A), 0) CFN_EOI

	CFN_IF (INCR CFN_NE 2) CFN_RETURN (-1) CFN_EOI

	CR CFN_D1D_AT (0) = CFN_SCDIV(CFN_SCADD(C1, CFN_SCSQRT(C2)), C3) CFN_EOI
	CR CFN_D1D_AT (1) = CFN_SCDIV(CFN_SCSUB(C1, CFN_SCSQRT(C2)), C3) CFN_EOI

	CFN_RETURN (0) CFN_EOI
	CFN_END

CFN_INTRINSIC(INTEGER, DCSQUAD,
(
	  CFN_DREAL A
	, CFN_DREAL B
	, CFN_DREAL C
	, CFN_INTEGER INCR
	, CFN_DCOMPLEX CFN_D1D(CR)
))
	CFN_DCMPLX_DECL(C1, -B, 0) CFN_EOI
	CFN_DCMPLX_DECL(C2, (B * B - 4 * A * C), 0) CFN_EOI
	CFN_DCMPLX_DECL(C3, (2 * A), 0) CFN_EOI

	CFN_IF (INCR CFN_NE 2) CFN_RETURN (-1) CFN_EOI

	CR CFN_D1D_AT (0) = CFN_DCDIV(CFN_DCADD(C1, CFN_DCSQRT(C2)), C3) CFN_EOI
	CR CFN_D1D_AT (1) = CFN_DCDIV(CFN_DCSUB(C1, CFN_DCSQRT(C2)), C3) CFN_EOI

	CFN_RETURN (0) CFN_EOI
	CFN_END

# define CFN_ZCSQUAD CFN_DCSQUAD

CFN_INTRINSIC(INTEGER, CSQUAD,
(
	  CFN_REAL A
	, CFN_REAL B
	, CFN_REAL C
	, CFN_INTEGER INCR
	, CFN_COMPLEX CFN_D1D(CR)
))
	CFN_INTEGER CSQUAD CFN_EOI
	CFN_CMPLX_DECL(C1, -B, 0) CFN_EOI
	CFN_CMPLX_DECL(C2, (B * B - 4 * A * C), 0) CFN_EOI
	CFN_CMPLX_DECL(C3, (2 * A), 0) CFN_EOI

	CSQUAD = -1 CFN_EOI
	CFN_IF (INCR CFN_NE 2) CFN_RETURN CSQUAD CFN_EOI
	CSQUAD = 0 CFN_EOI

	CR CFN_D1D_AT (0) = CFN_CDIV(CFN_CADD(C1, CFN_CSQRT(C2)), C3) CFN_EOI
	CR CFN_D1D_AT (1) = CFN_CDIV(CFN_CSUB(C1, CFN_CSQRT(C2)), C3) CFN_EOI

	CFN_RETURN CSQUAD CFN_EOI
	CFN_END

CFN_END_DECLS

#endif /* !CFN_COMPLEX_H */

/* EOF */