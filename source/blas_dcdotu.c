// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%dotu.ctpl template, do not edit.
// blas_dcdotu.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// COMPLEX*16 FUNCTION DCDOTU(N,CX,INCX,CY,INCY)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! COMPLEX FUNCTION DCDOTU(
 *   INTEGER N
 * , COMPLEX*16 CX(*)
 * , INTEGER INCX
 * , COMPLEX*16 CY(*)
 * , INTEGER INCY
 * )
 *
 * CFN_DCOMPLEX CFN_DCDOTU(
 *   CFN_INTEGER N
 * , CFN_DCOMPLEX CFN_INTENT CFN_D1D(CX)
 * , CFN_INTEGER INCX
 * , CFN_DCOMPLEX CFN_INTENT CFN_D1D(CY)
 * , CFN_INTEGER INCY
 * ) CFN_EOI
 *
 * \brief  Forms the dot product of two complex vectors. DCDOTU = X ^ H * Y
 *         Computes the dot product of vectors x and y.
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
CFN_FUNCTION(DCOMPLEX, DCDOTU,
(
	  CFN_INTEGER N
	, CFN_DCOMPLEX CFN_INTENT CFN_D1D(CX)
	, CFN_INTEGER INCX
	, CFN_DCOMPLEX CFN_INTENT CFN_D1D(CY)
	, CFN_INTEGER INCY
))
	CFN_INTRINSIC_DCL(DCADD) CFN_EOI
	CFN_INTRINSIC_DCL(DCMUL) CFN_EOI

	CFN_INTEGER II, IX, IY CFN_EOI
	CFN_DCMPLX_DECL(CTEMP, 0.0, 0.0) CFN_EOI
	CFN_DCMPLX_DECL(DCDOTU, 0.0, 0.0) CFN_EOI

	CFN_IF (N CFN_LE 0) CFN_RETURN DCDOTU CFN_EOI
	CFN_IF (INCX CFN_EQ 1 CFN_AND INCY CFN_EQ 1) CFN_THEN
		CFN_DO (II, 1, N)
			CTEMP = CFN_DCADD(CTEMP,
				CFN_DCMUL(
					  CX CFN_D1D_AT (II)
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
					  CX CFN_D1D_AT (IX)
					, CY CFN_D1D_AT (IY)
			)) CFN_EOI
			IX = IX + INCX CFN_EOI
			IY = IY + INCY CFN_EOI
		CFN_END_DO
	CFN_END_IF

	DCDOTU = CTEMP CFN_EOI

	CFN_RETURN DCDOTU CFN_EOI
	CFN_END

/* EOF */