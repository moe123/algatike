#!/bin/sh

#
# blas_%%dotc.sh
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
TEMPLATE_SEARCH[7]='\${SYM_INTRINSIC_CONJG}'
TEMPLATE_SEARCH[8]='\${SYM_INTRINSIC_CMUL}'
TEMPLATE_SEARCH[9]='\${SYM_CALL_CADD}'
TEMPLATE_SEARCH[10]='\${SYM_CALL_CONJG}'
TEMPLATE_SEARCH[11]='\${SYM_CALL_CMUL}'

do_blas_cdotc ()
{
	local dest="${SOURCE_PATH}/blas_cdotc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotc.ctpl"

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
	replace[7]='CONJG'
	replace[8]='CMUL'
	replace[9]='CFN_CADD'
	replace[10]='CFN_CONJG'
	replace[11]='CFN_CMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_scdotc ()
{
	local dest="${SOURCE_PATH}/blas_scdotc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotc.ctpl"

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
	replace[7]='SCONJG'
	replace[8]='SCMUL'
	replace[9]='CFN_SCADD'
	replace[10]='CFN_SCONJG'
	replace[11]='CFN_SCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_dcdotc ()
{
	local dest="${SOURCE_PATH}/blas_dcdotc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotc.ctpl"

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
	replace[7]='DCONJG'
	replace[8]='DCMUL'
	replace[9]='CFN_DCADD'
	replace[10]='CFN_DCONJG'
	replace[11]='CFN_DCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zcdotc ()
{
	local dest="${SOURCE_PATH}/blas_zcdotc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotc.ctpl"

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
	replace[7]='ZCONJG'
	replace[8]='ZCMUL'
	replace[9]='CFN_ZCADD'
	replace[10]='CFN_ZCONJG'
	replace[11]='CFN_ZCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zdotc ()
{
	local dest="${SOURCE_PATH}/blas_zdotc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%dotc.ctpl"

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
	replace[7]='ZCONJG'
	replace[8]='ZCMUL'
	replace[9]='CFN_ZCADD'
	replace[10]='CFN_ZCONJG'
	replace[11]='CFN_ZCMUL'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

main ()
{
	do_blas_cdotc
	do_blas_zdotc

	# Fixing naming convention.
	do_blas_scdotc
	do_blas_dcdotc
	do_blas_zcdotc

}; main $@

# EOF