// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%axpy.ctpl template, do not edit.
// blas_scaxpy.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// SUBROUTINE SCAXPY(N,CA,CX,INCX,CY,INCY)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! SUBROUTINE SCAXPY(
 *   INTEGER N
 * , COMPLEX*8 CA
 * , COMPLEX*8 CX(*)
 * , INTEGER INCX
 * , COMPLEX*8 CY(*)
 * , INTEGER INCY
 * )
 *
 * CFN_VOID CFN_SCAXPY(
 *   CFN_INTEGER N
 * , CFN_SCOMPLEX CA
 * , CFN_SCOMPLEX CFN_INTENT CFN_D1D(CX)
 * , CFN_INTEGER INCX
 * , CFN_SCOMPLEX CFN_D1D(CY)
 * , CFN_INTEGER INCY
 * ) CFN_EOI
 *
 * \brief  Constant times a vector plus a vector.
 * \param  INTEGER N
 *     Specifies the number of elements in input vector(s).
 * \param  COMPLEX*8 CA
 *     Specifies the scalar alpha.
 * \param  COMPLEX*8 CX(*)
 *     Dimension at least (1 + (N - 1) * | INCX |)
 * \param  INTEGER INCX
 *     Specifies the storage spacing between elements of CX.
 * \param  COMPLEX*8 CY(*)
 *     Dimension at least (1 + (N - 1) * | INCY |)
 * \param  INTEGER INCY
 *     Specifies the storage spacing between elements of CY.
 * \result VOID.
 *
 */
CFN_SUBROUTINE(SCAXPY, 
(
	  CFN_INTEGER N
	, CFN_SCOMPLEX CA
	, CFN_SCOMPLEX CFN_INTENT CFN_D1D(CX)
	, CFN_INTEGER INCX
	, CFN_SCOMPLEX CFN_D1D(CY)
	, CFN_INTEGER INCY
))
	CFN_INTRINSIC_DCL(SCADD) CFN_EOI
	CFN_INTRINSIC_DCL(SCMUL) CFN_EOI

	CFN_INTEGER II, IX, IY CFN_EOI

	CFN_EXTERNAL CFN_SREAL CFN_SCABS1(CFN_SCOMPLEX) CFN_EOI

	CFN_IF (N CFN_LE 0) CFN_RETURN CFN_EOI
	CFN_IF (CFN_SCABS1(CA) CFN_EQ 0.0) CFN_RETURN CFN_EOI
	CFN_IF (INCX CFN_EQ 1 CFN_AND INCY CFN_EQ 1) CFN_THEN
		CFN_DO (II, 1, N)
			CY CFN_D1D_AT (II) = CFN_SCADD(
				  CY CFN_D1D_AT (II)
				, CFN_SCMUL(CA, CX CFN_D1D_AT (II))
			) CFN_EOI
		CFN_END_DO
	CFN_ELSE
		IX = 1 CFN_EOI
		IY = 1 CFN_EOI
		CFN_IF (INCX CFN_LT 0) IX = (-N + 1) * INCX + 1 CFN_EOI
		CFN_IF (INCY CFN_LT 0) IY = (-N + 1) * INCY + 1 CFN_EOI
		CFN_DO (II, 1, N)
			CY CFN_D1D_AT (IY) = CFN_SCADD(
				  CY CFN_D1D_AT (IY)
				, CFN_SCMUL(CA, CX CFN_D1D_AT (IX))
			) CFN_EOI
			IX = IX + INCX CFN_EOI
			IY = IY + INCY CFN_EOI
		CFN_END_DO
	CFN_END_IF

	CFN_RETURN CFN_EOI
	CFN_END

/* EOF */