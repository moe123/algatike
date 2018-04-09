// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%abs1.ctpl template, do not edit.
// blas_cabs1.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// REAL FUNCTION CABS1(Z)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! REAL FUNCTION CABS1(COMPLEX Z)
 *
 * CFN_REAL CFN_CABS1(CFN_COMPLEX Z)
 *
 * \brief  Computes |Re(.)| + |Im(.)| of a complex number.
 * \param  COMPLEX Z
 * \result REAL.
 *
 */
CFN_FUNCTION(REAL, CABS1, 
(
	CFN_COMPLEX Z
))
	CFN_INTRINSIC_DCL(RABS)  CFN_EOI
	CFN_INTRINSIC_DCL(CREAL) CFN_EOI
	CFN_INTRINSIC_DCL(CIMAG) CFN_EOI

	CFN_REAL CABS1 = CFN_RABS(CFN_CREAL(Z)) + CFN_RABS(CFN_CIMAG(Z)) CFN_EOI
	
	CFN_RETURN CABS1 CFN_EOI
	CFN_END

/* EOF */