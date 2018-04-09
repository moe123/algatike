// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%axpy.ctpl template, do not edit.
// blas_zcaxpy.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// SUBROUTINE ZCAXPY(N,CA,CX,INCX,CY,INCY)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! SUBROUTINE ZCAXPY(
 *   INTEGER N
 * , COMPLEX*16 CA
 * , COMPLEX*16 CX(*)
 * , INTEGER INCX
 * , COMPLEX*16 CY(*)
 * , INTEGER INCY
 * )
 *
 * CFN_VOID CFN_ZCAXPY(
 *   CFN_INTEGER N
 * , CFN_ZCOMPLEX CA
 * , CFN_ZCOMPLEX CFN_INTENT CFN_D1D(CX)
 * , CFN_INTEGER INCX
 * , CFN_ZCOMPLEX CFN_D1D(CY)
 * , CFN_INTEGER INCY
 * ) CFN_EOI
 *
 * \brief  Constant times a vector plus a vector.
 * \param  INTEGER N
 *     Specifies the number of elements in input vector(s).
 * \param  COMPLEX*16 CA
 *     Specifies the scalar alpha.
 * \param  COMPLEX*16 CX(*)
 *     Dimension at least (1 + (N - 1) * | INCX |)
 * \param  INTEGER INCX
 *     Specifies the storage spacing between elements of CX.
 * \param  COMPLEX*16 CY(*)
 *     Dimension at least (1 + (N - 1) * | INCY |)
 * \param  INTEGER INCY
 *     Specifies the storage spacing between elements of CY.
 * \result VOID.
 *
 */
CFN_SUBROUTINE(ZCAXPY, 
(
	  CFN_INTEGER N
	, CFN_ZCOMPLEX CA
	, CFN_ZCOMPLEX CFN_INTENT CFN_D1D(CX)
	, CFN_INTEGER INCX
	, CFN_ZCOMPLEX CFN_D1D(CY)
	, CFN_INTEGER INCY
))
	CFN_INTRINSIC_DCL(ZCADD) CFN_EOI
	CFN_INTRINSIC_DCL(ZCMUL) CFN_EOI

	CFN_INTEGER II, IX, IY CFN_EOI

	CFN_EXTERNAL CFN_ZREAL CFN_ZCABS1(CFN_ZCOMPLEX) CFN_EOI

	CFN_IF (N CFN_LE 0) CFN_RETURN CFN_EOI
	CFN_IF (CFN_ZCABS1(CA) CFN_EQ 0.0) CFN_RETURN CFN_EOI
	CFN_IF (INCX CFN_EQ 1 CFN_AND INCY CFN_EQ 1) CFN_THEN
		CFN_DO (II, 1, N)
			CY CFN_D1D_AT (II) = CFN_ZCADD(
				  CY CFN_D1D_AT (II)
				, CFN_ZCMUL(CA, CX CFN_D1D_AT (II))
			) CFN_EOI
		CFN_END_DO
	CFN_ELSE
		IX = 1 CFN_EOI
		IY = 1 CFN_EOI
		CFN_IF (INCX CFN_LT 0) IX = (-N + 1) * INCX + 1 CFN_EOI
		CFN_IF (INCY CFN_LT 0) IY = (-N + 1) * INCY + 1 CFN_EOI
		CFN_DO (II, 1, N)
			CY CFN_D1D_AT (IY) = CFN_ZCADD(
				  CY CFN_D1D_AT (IY)
				, CFN_ZCMUL(CA, CX CFN_D1D_AT (IX))
			) CFN_EOI
			IX = IX + INCX CFN_EOI
			IY = IY + INCY CFN_EOI
		CFN_END_DO
	CFN_END_IF

	CFN_RETURN CFN_EOI
	CFN_END

/* EOF */