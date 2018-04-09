// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%abs1.ctpl template, do not edit.
// blas_scabs1.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// REAL*4 FUNCTION SCABS1(Z)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! REAL*4 FUNCTION SCABS1(COMPLEX*8 Z)
 *
 * CFN_SREAL CFN_SCABS1(CFN_SCOMPLEX Z)
 *
 * \brief  Computes |Re(.)| + |Im(.)| of a complex number.
 * \param  COMPLEX*8 Z
 * \result REAL*4.
 *
 */
CFN_FUNCTION(SREAL, SCABS1, 
(
	CFN_SCOMPLEX Z
))
	CFN_INTRINSIC_DCL(SRABS)  CFN_EOI
	CFN_INTRINSIC_DCL(SCREAL) CFN_EOI
	CFN_INTRINSIC_DCL(SCIMAG) CFN_EOI

	CFN_SREAL SCABS1 = CFN_SRABS(CFN_SCREAL(Z)) + CFN_SRABS(CFN_SCIMAG(Z)) CFN_EOI
	
	CFN_RETURN SCABS1 CFN_EOI
	CFN_END

/* EOF */