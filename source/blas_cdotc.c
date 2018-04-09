// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%dotc.ctpl template, do not edit.
// blas_cdotc.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// COMPLEX FUNCTION CDOTC(N,CX,INCX,CY,INCY)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! COMPLEX FUNCTION CDOTC(
 *   INTEGER N
 * , COMPLEX CX(*)
 * , INTEGER INCX
 * , COMPLEX CY(*)
 * , INTEGER INCY
 * )
 *
 * CFN_COMPLEX CFN_CDOTC(
 *   CFN_INTEGER N
 * , CFN_COMPLEX CFN_INTENT CFN_D1D(CX)
 * , CFN_INTEGER INCX
 * , CFN_COMPLEX CFN_INTENT CFN_D1D(CY)
 * , CFN_INTEGER INCY
 * ) CFN_EOI
 *
 * \brief  Forms the dot product of two complex vectors. CDOTC = X ^ H * Y
 *         Computes the dot product of the complex conjugate of vector x with vector y.
 * \param  INTEGER N
 *     Specifies the number of elements in input vector(s).
 * \param  COMPLEX CX(*)
 *     Dimension at least (1 + (N - 1) * | INCX |)
 * \param  INTEGER INCX
 *     Specifies the storage spacing between elements of CX.
 * \param  COMPLEX CY(*)
 *     Dimension at least (1 + (N - 1) * | INCY |)
 * \param  INTEGER INCY
 *     Specifies the storage spacing between elements of CY.
 * \result COMPLEX.
 *
 */
CFN_FUNCTION(COMPLEX, CDOTC,
(
	  CFN_INTEGER N
	, CFN_COMPLEX CFN_INTENT CFN_D1D(CX)
	, CFN_INTEGER INCX
	, CFN_COMPLEX CFN_INTENT CFN_D1D(CY)
	, CFN_INTEGER INCY
))
	CFN_INTRINSIC_DCL(CADD)  CFN_EOI
	CFN_INTRINSIC_DCL(CONJG) CFN_EOI
	CFN_INTRINSIC_DCL(CMUL)  CFN_EOI

	CFN_INTEGER II, IX, IY CFN_EOI
	CFN_CMPLX_DECL(CTEMP, 0.0, 0.0) CFN_EOI
	CFN_CMPLX_DECL(CDOTC, 0.0, 0.0) CFN_EOI

	CFN_IF (N CFN_LE 0) CFN_RETURN CDOTC CFN_EOI
	CFN_IF (INCX CFN_EQ 1 CFN_AND INCY CFN_EQ 1) CFN_THEN
		CFN_DO (II, 1, N)
			CTEMP = CFN_CADD(CTEMP,
				CFN_CMUL(
					  CFN_CONJG(CX CFN_D1D_AT (II))
					, CY CFN_D1D_AT (II)
			)) CFN_EOI
		CFN_END_DO
	CFN_ELSE
		IX = 1 CFN_EOI
		IY = 1 CFN_EOI
		CFN_IF (INCX CFN_LT 0) IX = (-N + 1) * INCX + 1 CFN_EOI
		CFN_IF (INCY CFN_LT 0) IY = (-N + 1) * INCY + 1 CFN_EOI
		CFN_DO (II, 1, N)
			CTEMP = CFN_CADD(CTEMP,
				CFN_CMUL(
					  CFN_CONJG(CX CFN_D1D_AT (IX))
					, CY CFN_D1D_AT (IY)
			)) CFN_EOI
			IX = IX + INCX CFN_EOI
			IY = IY + INCY CFN_EOI
		CFN_END_DO
	CFN_END_IF

	CDOTC = CTEMP CFN_EOI

	CFN_RETURN CDOTC CFN_EOI
	CFN_END

/* EOF */