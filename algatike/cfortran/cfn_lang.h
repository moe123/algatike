// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_lang.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#include <algatike/cfortran/cfn_itypes.h>
#include <algatike/cfortran/cfn_ctypes.h>

#ifndef CFN_LANG_H
#define CFN_LANG_H

CFN_BEGIN_DECLS

#	define CFN_LT  <
#	define CFN_LE  <=
#	define CFN_EQ  ==
#	define CFN_NE  !=
#	define CFN_GE  >=
#	define CFN_GT  >

#	define CFN_NOT !

#	define CFN_AND &&
#	define CFN_OR  ||

#	define CFN_EQV(A, B) (((A) && (B)) || !((A) && (B)))
#	define CFN_NEQV(A, B) CFN_NOT(CFN_EQV(A, B))

#	define CFN_BEGIN {

#	define CFN_END   }

#	define CFN_THEN    CFN_BEGIN
#	define CFN_IF      if
#	define CFN_ELSE_IF CFN_END else if
#	define CFN_ELSE    CFN_END else CFN_BEGIN
#	define CFN_END_IF  CFN_END

#	define CFN_RETURN return
#	define CFN_EOI    ;

#	define CFN_PARAMETER const
#	define CFN_INTENT    const 

#	define CFN_CALL

#	define CFN_LEN_TRIM strlen

#	define CFN_D1D_AT(IDX) [((IDX) - 1)]
#	define CFN_D2D_AT(COL, ROW) [(ROW - 1)][((COL) - 1)]
#	define CFN_D2D_S_AT(NCOLS, COL, ROW) [((NCOLS) * (ROW)) + (COL)]

#	define CFN_GOTO(LABEL_IDN) \
	goto CFN_PPCAT_2(L, LABEL_IDN)

#	define CFN_LABEL(LABEL_IDN) \
	CFN_PPCAT_2(L, LABEL_IDN):

#	define CFN_DO_STEP(IDX, START, STOP, STEPS) \
		for (size_t cfn_idx = 0, IDX = START \
			; cfn_idx < CFN_MAX(0, CFN_CAST(size_t, ((STOP - START + STEPS) / STEPS)))\
			; cfn_idx++, IDX += STEPS \
		) {

#	define CFN_DO_LABEL_STEP(LABEL_IDN, IDX, START, STOP, STEPS) \
		size_t CFN_PPCAT_7(cfn_jmp_, IDX, START, STOP, STEPS, L, LABEL_IDN) = CFN_MAX(0, CFN_CAST(size_t, ((STOP - START + STEPS) / STEPS))) - 1; \
		CFN_DO_STEP(IDX, START, STOP, STEPS) \
			if (cfn_idx == CFN_PPCAT_7(cfn_jmp_, IDX, START, STOP, STEPS, L, LABEL_IDN)) { \
				CFN_GOTO(LABEL_IDN); \
			}

#	define CFN_DO_WHILE() \
		while((COND)) {

#	define CFN_DO(IDX, START, STOP) \
		CFN_DO_STEP(IDX, START, STOP, 1)

#	define CFN_DO_LABEL(LABEL_IDN, IDX_NAME, START, STOP) \
		CFN_DO_LABEL_STEP(LABEL_IDN, IDX_NAME, START, STOP, 1)

#	define CFN_CONTINUE(LABEL_IDN) } CFN_LABEL(LABEL_IDN) ;

#	define CFN_END_DO }

#	if CFN_DEBUG
#		define CFN_INTRINSIC_DCL(INTRINSIC_NAME) \
			static int CFN_PPCAT_2(CFN_INTRINSIC_, INTRINSIC_NAME) = 0; \
			(void) CFN_PPCAT_2(CFN_INTRINSIC_, INTRINSIC_NAME)
# else
#		define CFN_INTRINSIC_DCL(INTRINSIC_NAME) 
# endif

#	define CFN_INTRINSIC(RETURN_TYPE, INTRINSIC_NAME, ARGV_TUPLE_DCL) \
		CFN_STATIC_ALWAYS_INLINE \
		CFN_PPCAT_2(CFN_, RETURN_TYPE) CFN_PPCAT_2(CFN_, INTRINSIC_NAME) \
		ARGV_TUPLE_DCL {

#	define CFN_FUNCTION(RETURN_TYPE, FUNCTION_NAME, ARGV_TUPLE_DCL) \
		CFN_PPCAT_2(CFN_, RETURN_TYPE) CFN_PPCAT_2(CFN_, FUNCTION_NAME) \
		ARGV_TUPLE_DCL {

#	define CFN_SUBROUTINE(SUBROUTINE_NAME, ARGV_TUPLE_DCL) \
		CFN_FUNCTION(VOID, SUBROUTINE_NAME, ARGV_TUPLE_DCL)

#	define CFN_D1D_DECL(TYPE1D, NAME1D, N) \
		CFN_VECTOR_DECL(TYPE1D, NAME1D, N)

#	define CFN_D1D_NEW(TYPE1D, NAME1D, N) \
		CFN_VECTOR_NEW(TYPE1D, NAME1D, N)

#	define CFN_D1D_DEL(NAME1D) \
		CFN_VECTOR_DEL(NAME1D)

#	define CFN_D2D_DECL(TYPE2D, NAME2D, M, N) \
		CFN_CMATRIX_DECL(TYPE2D, NAME2D, M, N)

#	define CFN_D2D_NEW(TYPE2D, NAME2D, M, N) \
		CFN_MATRIX_NEW(TYPE2D, NAME2D, M, N)

#	define CFN_D2D_DEL(NAME2D, M) \
		CFN_MATRIX_DEL(NAME2D, M)

CFN_END_DECLS

#endif /* !CFN_LANG_H */

/* EOF */