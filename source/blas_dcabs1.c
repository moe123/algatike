// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%abs1.ctpl template, do not edit.
// blas_dcabs1.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// REAL*8 FUNCTION DCABS1(Z)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! REAL*8 FUNCTION DCABS1(COMPLEX*16 Z)
 *
 * CFN_DREAL CFN_DCABS1(CFN_DCOMPLEX Z)
 *
 * \brief  Computes |Re(.)| + |Im(.)| of a complex number.
 * \param  COMPLEX*16 Z
 * \result REAL*8.
 *
 */
CFN_FUNCTION(DREAL, DCABS1, 
(
	CFN_DCOMPLEX Z
))
	CFN_INTRINSIC_DCL(DRABS)  CFN_EOI
	CFN_INTRINSIC_DCL(DCREAL) CFN_EOI
	CFN_INTRINSIC_DCL(DCIMAG) CFN_EOI

	CFN_DREAL DCABS1 = CFN_DRABS(CFN_DCREAL(Z)) + CFN_DRABS(CFN_DCIMAG(Z)) CFN_EOI
	
	CFN_RETURN DCABS1 CFN_EOI
	CFN_END

/* EOF */