// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%dotc.ctpl template, do not edit.
// blas_dcdotc.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// COMPLEX*16 FUNCTION DCDOTC(N,CX,INCX,CY,INCY)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! COMPLEX FUNCTION DCDOTC(
 *   INTEGER N
 * , COMPLEX*16 CX(*)
 * , INTEGER INCX
 * , COMPLEX*16 CY(*)
 * , INTEGER INCY
 * )
 *
 * CFN_DCOMPLEX CFN_DCDOTC(
 *   CFN_INTEGER N
 * , CFN_DCOMPLEX CFN_INTENT CFN_D1D(CX)
 * , CFN_INTEGER INCX
 * , CFN_DCOMPLEX CFN_INTENT CFN_D1D(CY)
 * , CFN_INTEGER INCY
 * ) CFN_EOI
 *
 * \brief  Forms the dot product of two complex vectors. DCDOTC = X ^ H * Y
 *         Computes the dot product of the complex conjugate of vector x with vector y.
 * \param  INTEGER N
 *     Specifies the number of elements in input vector(s).
 * \param  COMPLEX*16 CX(*)
 *     Dimension at least (1 + (N - 1) * | INCX |)
 * \param  INTEGER INCX
 *     Specifies the storage spacing between elements of CX.
 * \param  COMPLEX*16 CY(*)
 *     Dimension at least (1 + (N - 1) * | INCY |)
 * \param  INTEGER INCY
 *     Specifies the storage spacing between elements of CY.
 * \result COMPLEX*16.
 *
 */
CFN_FUNCTION(DCOMPLEX, DCDOTC,
(
	  CFN_INTEGER N
	, CFN_DCOMPLEX CFN_INTENT CFN_D1D(CX)
	, CFN_INTEGER INCX
	, CFN_DCOMPLEX CFN_INTENT CFN_D1D(CY)
	, CFN_INTEGER INCY
))
	CFN_INTRINSIC_DCL(DCADD)  CFN_EOI
	CFN_INTRINSIC_DCL(DCONJG) CFN_EOI
	CFN_INTRINSIC_DCL(DCMUL)  CFN_EOI

	CFN_INTEGER II, IX, IY CFN_EOI
	CFN_DCMPLX_DECL(CTEMP, 0.0, 0.0) CFN_EOI
	CFN_DCMPLX_DECL(DCDOTC, 0.0, 0.0) CFN_EOI

	CFN_IF (N CFN_LE 0) CFN_RETURN DCDOTC CFN_EOI
	CFN_IF (INCX CFN_EQ 1 CFN_AND INCY CFN_EQ 1) CFN_THEN
		CFN_DO (II, 1, N)
			CTEMP = CFN_DCADD(CTEMP,
				CFN_DCMUL(
					  CFN_DCONJG(CX CFN_D1D_AT (II))
					, CY CFN_D1D_AT (II)
			)) CFN_EOI
		CFN_END_DO
	CFN_ELSE
		IX = 1 CFN_EOI
		IY = 1 CFN_EOI
		CFN_IF (INCX CFN_LT 0) IX = (-N + 1) * INCX + 1 CFN_EOI
		CFN_IF (INCY CFN_LT 0) IY = (-N + 1) * INCY + 1 CFN_EOI
		CFN_DO (II, 1, N)
			CTEMP = CFN_DCADD(CTEMP,
				CFN_DCMUL(
					  CFN_DCONJG(CX CFN_D1D_AT (IX))
					, CY CFN_D1D_AT (IY)
			)) CFN_EOI
			IX = IX + INCX CFN_EOI
			IY = IY + INCY CFN_EOI
		CFN_END_DO
	CFN_END_IF

	DCDOTC = CTEMP CFN_EOI

	CFN_RETURN DCDOTC CFN_EOI
	CFN_END

/* EOF */