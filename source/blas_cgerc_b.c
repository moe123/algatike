// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%gerc_b.ctpl template, do not edit.
// blas_cgerc_b.c
//
// Copyright (C) 2018 Moe123. All rights reserved. 
//

// SUBROUTINE CGERC_B(M,N,ALPHA,X,INCX,Y,INCY,A,LDA)
// Online html documentation and credits available at:
// http://www netlib org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! SUBROUTINE CGERC_B(M,N,ALPHA,X,INCX,Y,INCY,A,LDA)(
 *   INTEGER M
 * , INTEGER N
 * , COMPLEX ALPHA
 * , COMPLEX X(*)
 * , INTEGER INCX
 * , COMPLEX Y(*)
 * , INTEGER INCY
 * , COMPLEX A(LDA, *)
 * , INTEGER LDA
 * )
 *
 * CFN_VOID CFN_CGERC_B(
 *   CFN_INTEGER M
 * , CFN_INTEGER N
 * , CFN_COMPLEX ALPHA
 * , CFN_COMPLEX CFN_D1D(X)
 * , CFN_INTEGER INCX
 * , CFN_COMPLEX CFN_D1D(Y)
 * , CFN_INTEGER INCY
 * , CFN_COMPLEX CFN_B2D(A)
 * , CFN_INTEGER LDA
 * ) CFN_EOI
 *
 * \brief  Performs the rank 1 operation  A := alpha * x * y ** H + A
 * \param  INTEGER M
 *     Specifies the number of rows of the matrix A.
 * \param  INTEGER N
 *     Specifies the number of columns of the matrix A.
 * \param  COMPLEX ALPHA
 *     Specifies the scalar alpha.
 * \param  COMPLEX X(*)
 *     Dimension at least (1 + (m - 1) * | INCX |).
 * \param  INTEGER INCX
 *     Specifies the increment for the elements of X.
 * \param  COMPLEX Y(*)
 *     Dimension at least (1 + (n - 1) * | INCY |).
 * \param  INTEGER INCY
 *     Specifies the increment for the elements of Y.
 * \param  COMPLEX A(LDA, *)
 *     Dimension (LDA, N), must contain the matrix of coefficients.
 * \param  INTEGER LDA
 *     LDA specifies the first dimension of A. LDA must be at least MAX(1, M).
 * \result VOID
 *
 */
CFN_SUBROUTINE(CGERC_B,
(
	  CFN_INTEGER M
	, CFN_INTEGER N
	, CFN_COMPLEX ALPHA
	, CFN_COMPLEX CFN_INTENT CFN_D1D(X)
	, CFN_INTEGER INCX
	, CFN_COMPLEX CFN_INTENT CFN_D1D(Y)
	, CFN_INTEGER INCY
	, CFN_COMPLEX CFN_B2D(A)
	, CFN_INTEGER LDA
))
	CFN_INTRINSIC_DCL(CONJG) CFN_EOI
	CFN_INTRINSIC_DCL(CMUL)  CFN_EOI
	CFN_INTRINSIC_DCL(CADD)  CFN_EOI
	CFN_INTRINSIC_DCL(CEQ)   CFN_EOI
	CFN_INTRINSIC_DCL(CNE)   CFN_EOI

	CFN_INTRINSIC_DCL(IMAX) CFN_EOI

	CFN_PARAMETER CFN_CMPLX_DECL(ZERO, 0.0, 0.0) CFN_EOI

	CFN_COMPLEX TEMP CFN_EOI
	CFN_INTEGER II, INFO, IX, J, JY, KX CFN_EOI

	CFN_EXTERNAL CFN_VOID CFN_XERBLA(CFN_INTENT CFN_CHARACTERS, CFN_INTEGER) CFN_EOI

	INFO = 0 CFN_EOI
	CFN_IF (M CFN_LT 0) CFN_THEN
		INFO = 1 CFN_EOI
	CFN_ELSE_IF (N CFN_LT 0) CFN_THEN
		INFO = 2 CFN_EOI
	CFN_ELSE_IF (INCX CFN_EQ 0) CFN_THEN
		INFO = 5 CFN_EOI
	CFN_ELSE_IF (INCY CFN_EQ 0) CFN_THEN
		INFO = 7 CFN_EOI
	CFN_ELSE_IF (LDA CFN_LT CFN_IMAX(1, M)) CFN_THEN
		INFO = 9 CFN_EOI
	CFN_END_IF
	CFN_IF (INFO CFN_NE 0) CFN_THEN
		CFN_CALL CFN_XERBLA("CGERC_B", INFO) CFN_EOI
		CFN_RETURN CFN_EOI
	CFN_END_IF
	CFN_IF ((M CFN_EQ 0) CFN_OR (N CFN_EQ 0) CFN_OR CFN_CEQ(ALPHA, ZERO)) CFN_RETURN CFN_EOI

	CFN_IF (INCY CFN_GT 0) CFN_THEN
		JY = 1 CFN_EOI
	CFN_ELSE
		JY = 1 - (N - 1) * INCY CFN_EOI
	CFN_END_IF
	CFN_IF (INCX CFN_EQ 1) CFN_THEN
		CFN_DO_LABEL(20, J, 1, N)
			CFN_IF (CFN_CNE(Y CFN_D1D_AT (JY), ZERO)) CFN_THEN
				TEMP = CFN_CMUL(ALPHA, CFN_CONJG(Y CFN_D1D_AT (JY))) CFN_EOI
				CFN_DO_LABEL(10, II, 1, M)
					A CFN_B2D_AT (N, II, J) = CFN_CADD(
						  A CFN_B2D_AT (N, II, J)
						, CFN_CMUL(X CFN_D1D_AT (II), TEMP)
					) CFN_EOI
				CFN_CONTINUE(10)
			CFN_END_IF
			JY = JY + INCY CFN_EOI
		CFN_CONTINUE(20)
	CFN_ELSE
		CFN_IF (INCX CFN_GT 0) CFN_THEN
			KX = 1 CFN_EOI
		CFN_ELSE
			KX = 1 - (M - 1) * INCX CFN_EOI
		CFN_END_IF
		CFN_DO_LABEL(40, J, 1, N)
			CFN_IF (CFN_CNE(Y CFN_D1D_AT (JY), ZERO)) CFN_THEN
				TEMP = CFN_CMUL(ALPHA, CFN_CONJG(Y CFN_D1D_AT (JY))) CFN_EOI
				IX = KX CFN_EOI
				CFN_DO_LABEL(30, II, 1, M)
					A CFN_B2D_AT (N, II, J) = CFN_CADD(
						  A CFN_B2D_AT (N, II, J)
						, CFN_CMUL(X CFN_D1D_AT (IX), TEMP)
					) CFN_EOI
					IX = IX + INCX CFN_EOI
				CFN_CONTINUE(30)
			CFN_END_IF
			JY = JY + INCY CFN_EOI
		CFN_CONTINUE(40)
	CFN_END_IF

	CFN_RETURN CFN_EOI
	CFN_END

/* EOF */