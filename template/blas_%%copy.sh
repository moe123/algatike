#!/bin/sh

#
# blas_%%copy.sh
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

do_blas_ccopy ()
{
	local dest="${SOURCE_PATH}/blas_ccopy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%copy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='c'
	replace[1]='C'
	replace[2]='COMPLEX'
	replace[3]='CFN_COMPLEX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_sccopy ()
{
	local dest="${SOURCE_PATH}/blas_sccopy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%copy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	search[0]='\${SYM_PREFIX_LOWER}'
	search[1]='\${SYM_PREFIX_UPPER}'
	search[2]='\${SYM_FORTRAN_COMPLEX_TYPE}'
	search[3]='\${SYM_COMPLEX_TYPE}'

	replace[0]='sc'
	replace[1]='SC'
	replace[2]='COMPLEX*8'
	replace[3]='CFN_SCOMPLEX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_dccopy ()
{
	local dest="${SOURCE_PATH}/blas_dccopy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%copy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	search[0]='\${SYM_PREFIX_LOWER}'
	search[1]='\${SYM_PREFIX_UPPER}'
	search[2]='\${SYM_FORTRAN_COMPLEX_TYPE}'
	search[3]='\${SYM_COMPLEX_TYPE}'

	replace[0]='dc'
	replace[1]='DC'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_DCOMPLEX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zccopy ()
{
	local dest="${SOURCE_PATH}/blas_zccopy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%copy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	search[0]='\${SYM_PREFIX_LOWER}'
	search[1]='\${SYM_PREFIX_UPPER}'
	search[2]='\${SYM_FORTRAN_COMPLEX_TYPE}'
	search[3]='\${SYM_COMPLEX_TYPE}'

	replace[0]='zc'
	replace[1]='ZC'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_ZCOMPLEX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

do_blas_zcopy ()
{
	local dest="${SOURCE_PATH}/blas_zcopy.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%copy.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	search[0]='\${SYM_PREFIX_LOWER}'
	search[1]='\${SYM_PREFIX_UPPER}'
	search[2]='\${SYM_FORTRAN_COMPLEX_TYPE}'
	search[3]='\${SYM_COMPLEX_TYPE}'

	replace[0]='z'
	replace[1]='Z'
	replace[2]='COMPLEX*16'
	replace[3]='CFN_ZCOMPLEX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]
}

main ()
{
	do_blas_ccopy
	do_blas_zcopy

	# Fixing naming convention.
	do_blas_sccopy
	do_blas_dccopy
	do_blas_zccopy
}; main $@

# EOF