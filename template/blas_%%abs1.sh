#!/bin/sh

#
# blas_%%abs1.sh
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
TEMPLATE_SEARCH[2]='\${SYM_FORTRAN_REAL_TYPE}'
TEMPLATE_SEARCH[3]='\${SYM_FORTRAN_COMPLEX_TYPE}'
TEMPLATE_SEARCH[4]='\${SYM_REAL_SHORT_TYPE}'
TEMPLATE_SEARCH[5]='\${SYM_COMPLEX_TYPE}'
TEMPLATE_SEARCH[6]='\${SYM_REAL_TYPE}'
TEMPLATE_SEARCH[7]='\${SYM_INTRINSIC_RABS}'
TEMPLATE_SEARCH[8]='\${SYM_INTRINSIC_CREAL}'
TEMPLATE_SEARCH[9]='\${SYM_INTRINSIC_CIMAG}'
TEMPLATE_SEARCH[10]='\${SYM_CALL_ABS}'
TEMPLATE_SEARCH[11]='\${SYM_CALL_CREAL}'
TEMPLATE_SEARCH[12]='\${SYM_CALL_CIMAG}'

do_blas_scabs1 ()
{
	local dest="${SOURCE_PATH}/blas_scabs1.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%abs1.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='sc'
	replace[1]='SC'
	replace[2]='REAL*4'
	replace[3]='COMPLEX*8'
	replace[4]='SREAL'
	replace[5]='CFN_SCOMPLEX'
	replace[6]='CFN_SREAL'
	replace[7]='SRABS'
	replace[8]='SCREAL'
	replace[9]='SCIMAG'
	replace[10]='CFN_SRABS'
	replace[11]='CFN_SCREAL'
	replace[12]='CFN_SCIMAG'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_cabs1 ()
{
	local dest="${SOURCE_PATH}/blas_cabs1.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%abs1.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='c'
	replace[1]='C'
	replace[2]='REAL'
	replace[3]='COMPLEX'
	replace[4]='REAL'
	replace[5]='CFN_COMPLEX'
	replace[6]='CFN_REAL'
	replace[7]='RABS'
	replace[8]='CREAL'
	replace[9]='CIMAG'
	replace[10]='CFN_RABS'
	replace[11]='CFN_CREAL'
	replace[12]='CFN_CIMAG'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_dcabs1 ()
{
	local dest="${SOURCE_PATH}/blas_dcabs1.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%abs1.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='dc'
	replace[1]='DC'
	replace[2]='REAL*8'
	replace[3]='COMPLEX*16'
	replace[4]='DREAL'
	replace[5]='CFN_DCOMPLEX'
	replace[6]='CFN_DREAL'
	replace[7]='DRABS'
	replace[8]='DCREAL'
	replace[9]='DCIMAG'
	replace[10]='CFN_DRABS'
	replace[11]='CFN_DCREAL'
	replace[12]='CFN_DCIMAG'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zcabs1 ()
{
	local dest="${SOURCE_PATH}/blas_zcabs1.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%abs1.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='zc'
	replace[1]='ZC'
	replace[2]='REAL*8'
	replace[3]='COMPLEX*16'
	replace[4]='ZREAL'
	replace[5]='CFN_ZCOMPLEX'
	replace[6]='CFN_ZREAL'
	replace[7]='ZRABS'
	replace[8]='ZCREAL'
	replace[9]='ZCIMAG'
	replace[10]='CFN_ZRABS'
	replace[11]='CFN_ZCREAL'
	replace[12]='CFN_ZCIMAG'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zabs1 ()
{
	local dest="${SOURCE_PATH}/blas_zabs1.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%abs1.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='z'
	replace[1]='Z'
	replace[2]='REAL*8'
	replace[3]='COMPLEX*16'
	replace[4]='ZREAL'
	replace[5]='CFN_ZCOMPLEX'
	replace[6]='CFN_ZREAL'
	replace[7]='ZRABS'
	replace[8]='ZCREAL'
	replace[9]='ZCIMAG'
	replace[10]='CFN_ZRABS'
	replace[11]='CFN_ZCREAL'
	replace[12]='CFN_ZCIMAG'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

main ()
{
	do_blas_scabs1
	do_blas_dcabs1

	# Fixing naming convention.
	do_blas_cabs1
	do_blas_zcabs1
	do_blas_zabs1
}; main $@

# EOF