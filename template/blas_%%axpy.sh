#!/bin/sh

#
# blas_%%axpy.sh
#
# Copyright (C) 2018 Moe123. All rights reserved.
#

pushd ()
{
	command pushd "${@}" > /dev/null
}

popd ()
{
	command popd "${@}" > /dev/null
}

abspath ()
{
	pushd `echo $(dirname ${1})`
		echo $(dirname `pwd`)
	popd
}

replace_all ()
{
	local -a search=("${!2}")
	local -a replace=("${!3}")

	for i in "${!search[@]}"; do
		sed -e 's/'"${search[$i]}"'/'"${replace[$i]}"'/g' "${1}" > "${1}_"
		rm -f "${1}"
		mv "${1}_" "${1}"
	done
	perl -pi -e 'chomp if eof' "${1}"
}

LOCAL_PATH=$(abspath ${0})
SOURCE_PATH=${LOCAL_PATH}/source
TEMPLATE_PATH=${LOCAL_PATH}/template

declare -a TEMPLATE_SEARCH

TEMPLATE_SEARCH[0]='\${SYM_PREFIX_LOWER}'
TEMPLATE_SEARCH[1]='\${SYM_PREFIX_UPPER}'
TEMPLATE_SEARCH[2]='\${SYM_FORTRAN_COMPLEX_TYPE}'
TEMPLATE_SEARCH[3]='\${SYM_COMPLEX_TYPE}'
TEMPLATE_SEARCH[4]='\${SYM_REAL_TYPE}'
TEMPLATE_SEARCH[5]='\${SYM_INTRINSIC_CADD}'
TEMPLATE_SEARCH[6]='\${SYM_INTRINSIC_CMUL}'
TEMPLATE_SEARCH[7]='\${SYM_CALL_CADD}'
TEMPLATE_SEARCH[8]='\${SYM_CALL_CMUL}'
TEMPLATE_SEARCH[9]='\${SYM_CALL_CABS1}'

do_blas_caxpy ()
{
	local dest="${SOURCE_PATH}/blas_caxpy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%axpy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='c'
	replace[1]='C'
	replace[2]='COMPLEX'
	replace[3]='CFN_COMPLEX'
	replace[4]='CFN_REAL'
	replace[5]='CADD'
	replace[6]='CMUL'
	replace[7]='CFN_CADD'
	replace[8]='CFN_CMUL'
	replace[9]='CFN_CABS1'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_scaxpy ()
{
	local dest="${SOURCE_PATH}/blas_scaxpy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%axpy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='sc'
	replace[1]='SC'
	replace[2]='COMPLEX*8'
	replace[3]='CFN_SCOMPLEX'
	replace[4]='CFN_SREAL'
	replace[5]='SCADD'
	replace[6]='SCMUL'
	replace[7]='CFN_SCADD'
	replace[8]='CFN_SCMUL'
	replace[9]='CFN_SCABS1'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_dcaxpy ()
{
	local dest="${SOURCE_PATH}/blas_dcaxpy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%axpy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='dc'
	replace[1]='DC'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_DCOMPLEX'
	replace[4]='CFN_DREAL'
	replace[5]='DCADD'
	replace[6]='DCMUL'
	replace[7]='CFN_DCADD'
	replace[8]='CFN_DCMUL'
	replace[9]='CFN_DCABS1'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zcaxpy ()
{
	local dest="${SOURCE_PATH}/blas_zcaxpy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%axpy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='zc'
	replace[1]='ZC'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_ZCOMPLEX'
	replace[4]='CFN_ZREAL'
	replace[5]='ZCADD'
	replace[6]='ZCMUL'
	replace[7]='CFN_ZCADD'
	replace[8]='CFN_ZCMUL'
	replace[9]='CFN_ZCABS1'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zaxpy ()
{
	local dest="${SOURCE_PATH}/blas_zaxpy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%axpy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='z'
	replace[1]='Z'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_ZCOMPLEX'
	replace[4]='CFN_ZREAL'
	replace[5]='ZCADD'
	replace[6]='ZCMUL'
	replace[7]='CFN_ZCADD'
	replace[8]='CFN_ZCMUL'
	replace[9]='CFN_ZCABS1'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

main ()
{
	do_blas_caxpy
	do_blas_zaxpy

	# Fixing naming convention.
	do_blas_scaxpy
	do_blas_dcaxpy
	do_blas_zcaxpy
}; main $@

# EOF