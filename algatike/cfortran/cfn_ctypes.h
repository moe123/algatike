// # -*- coding: utf-8, tab-width: 3 -*-

//
// cfn_ctypes.h
//
// Copyright (C) 2018 Moe123. All rights reserved.
//

#include <algatike/cfortran/cfn_itypes.h>

#ifndef CFN_CTYPES_H
#define CFN_CTYPES_H

CFN_BEGIN_DECLS

#	define CFN_CHARACTER          char
#	define CFN_UCHARACTER         unsigned char
#	define CFN_CHARACTERS         CFN_CHARACTER *
#	define CFN_UCHARACTERS        CFN_UCHARACTER *

#	define CFN_BYTE               CFN_INTEGER8
#	define CFN_UBYTE              CFN_UINTEGER8
#	define CFN_BYTES              CFN_BYTE *
#	define CFN_UBYTES             CFN_UBYTE *

#	define CFN_TOICHAR(C)         CFN_CAST(CFN_INTEGER32, C)
#	define CFN_TOCHAR(I)          CFN_CAST(CFN_CHARACTER, I)
#	define CFN_TOIACHAR           CFN_CAST(CFN_INTEGER32, C)
#	define CFN_TOACHAR(I)         CFN_CAST(CFN_CHARACTER, I)

#	define CFN_TOUCHAR(I)         CFN_CAST(CFN_UCHARACTER, I)
#	define CFN_TOUACHAR(I)        CFN_CAST(CFN_UCHARACTER, I)

#	define CFN_TOINT(X)           CFN_CAST(CFN_INTEGER,   X)
#	define CFN_TOINT8(X)          CFN_CAST(CFN_INTEGER8,  X)
#	define CFN_TOINT32(X)         CFN_CAST(CFN_INTEGER32, X)
#	define CFN_TOINT64(X)         CFN_CAST(CFN_INTEGER64, X)

#	define CFN_TOUINT(X)          CFN_CAST(CFN_UINTEGER,   X)
#	define CFN_TOUINT8(X)         CFN_CAST(CFN_UINTEGER8,  X)
#	define CFN_TOUINT32(X)        CFN_CAST(CFN_UINTEGER32, X)
#	define CFN_TOUINT64(X)        CFN_CAST(CFN_UINTEGER64, X)

#	define CFN_TOREAL(X)          CFN_CAST(CFN_REAL,  X)
#	define CFN_TOSREAL(X)         CFN_CAST(CFN_SREAL, X)
#	define CFN_TODREAL(X)         CFN_CAST(CFN_DREAL, X)
#	define CFN_TOZREAL(X)         CFN_CAST(CFN_ZREAL, X)

#	define CFN_TOLOGICAL(X)       (X) ? CFN_TRUE : CFN_FALSE

#	define CFN_IBSET(A, POS)      (A) |= 1 << (POS)
#	define CFN_IBCLR(A, POS)      (A) &= ~(1 << (POS));

#	define CFN_IAND(A, B)         (A) & (B)
#	define CFN_IOR(A, B)          (A) | (B)
#	define CFN_IEOR(A, B)         (A) ^ (B)
#	define CFN_INOT(A)            ~(A)

#	define CFN_BIT_SIZE(I)        (CFN_SIZEOF((I)) * CHAR_BIT)

CFN_END_DECLS

#endif /* !CFN_CTYPES_H */

/* EOF */