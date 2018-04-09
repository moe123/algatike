#!/bin/sh

#
# blas_%%dotu.sh
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
TEMPLATE_SEARCH[3]='\${SYM_COMPLEX_SHORT_TYPE}'
TEMPLATE_SEARCH[4]='\${SYM_COMPLEX_TYPE}'
TEMPLATE_SEARCH[5]='\${SYM_CMPLX_DECL}'
TEMPLATE_SEARCH[6]='\${SYM_INTRINSIC_CADD}'
TEMPLATE_SEARCH[7]='\${SYM_INTRINSIC_CMUL}'
TEMPLATE_SEARCH[8]='\${SYM_CALL_CADD}'
TEMPLATE_SEARCH[9]='\${SYM_CALL_CMUL}'

do_blas_cdotu ()
{
	local dest="${SOURCE_PATH}/blas_cdotu.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotu.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='c'
	replace[1]='C'
	replace[2]='COMPLEX'
	replace[3]='COMPLEX'
	replace[4]='CFN_COMPLEX'
	replace[5]='CFN_CMPLX_DECL'
	replace[6]='CADD'
	replace[7]='CMUL'
	replace[8]='CFN_CADD'
	replace[9]='CFN_CMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_scdotu ()
{
	local dest="${SOURCE_PATH}/blas_scdotu.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotu.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='sc'
	replace[1]='SC'
	replace[2]='COMPLEX*8'
	replace[3]='SCOMPLEX'
	replace[4]='CFN_SCOMPLEX'
	replace[5]='CFN_SCMPLX_DECL'
	replace[6]='SCADD'
	replace[7]='SCMUL'
	replace[8]='CFN_SCADD'
	replace[9]='CFN_SCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_dcdotu ()
{
	local dest="${SOURCE_PATH}/blas_dcdotu.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotu.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='dc'
	replace[1]='DC'
	replace[2]='COMPLEX*16'
	replace[3]='DCOMPLEX'
	replace[4]='CFN_DCOMPLEX'
	replace[5]='CFN_DCMPLX_DECL'
	replace[6]='DCADD'
	replace[7]='DCMUL'
	replace[8]='CFN_DCADD'
	replace[9]='CFN_DCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zcdotu ()
{
	local dest="${SOURCE_PATH}/blas_zcdotu.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotu.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='zc'
	replace[1]='ZC'
	replace[2]='COMPLEX*16'
	replace[3]='ZCOMPLEX'
	replace[4]='CFN_ZCOMPLEX'
	replace[5]='CFN_ZCMPLX_DECL'
	replace[6]='ZCADD'
	replace[7]='ZCMUL'
	replace[8]='CFN_ZCADD'
	replace[9]='CFN_ZCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zdotu ()
{
	local dest="${SOURCE_PATH}/blas_zdotu.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotu.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='z'
	replace[1]='Z'
	replace[2]='COMPLEX*16'
	replace[3]='ZCOMPLEX'
	replace[4]='CFN_ZCOMPLEX'
	replace[5]='CFN_ZCMPLX_DECL'
	replace[6]='ZCADD'
	replace[7]='ZCMUL'
	replace[8]='CFN_ZCADD'
	replace[9]='CFN_ZCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

main ()
{
	do_blas_cdotu
	do_blas_zdotu

	# Fixing naming convention.
	do_blas_scdotu
	do_blas_dcdotu
	do_blas_zcdotu

}; main $@

# EOF