// # -*- coding: utf-8, tab-width: 3 -*-

//
// Assembled from blas_%%abs1.ctpl template, do not edit.
// blas_zabs1.c
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

// REAL*8 FUNCTION ZABS1(Z)
// Online html documentation and credits available at:
// http://www.netlib.org/lapack/explore-html/
//

#include <algatike/cfortran/cfn_lang.h>
#include <algatike/cfortran/cfn_math.h>
#include <algatike/cfortran/cfn_complex.h>

/*! REAL*8 FUNCTION ZABS1(COMPLEX*16 Z)
 *
 * CFN_ZREAL CFN_ZABS1(CFN_ZCOMPLEX Z)
 *
 * \brief  Computes |Re(.)| + |Im(.)| of a complex number.
 * \param  COMPLEX*16 Z
 * \result REAL*8.
 *
 */
CFN_FUNCTION(ZREAL, ZABS1, 
(
	CFN_ZCOMPLEX Z
))
	CFN_INTRINSIC_DCL(ZRABS)  CFN_EOI
	CFN_INTRINSIC_DCL(ZCREAL) CFN_EOI
	CFN_INTRINSIC_DCL(ZCIMAG) CFN_EOI

	CFN_ZREAL ZABS1 = CFN_ZRABS(CFN_ZCREAL(Z)) + CFN_ZRABS(CFN_ZCIMAG(Z)) CFN_EOI
	
	CFN_RETURN ZABS1 CFN_EOI
	CFN_END

/* EOF */