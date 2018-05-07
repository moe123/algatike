#!/bin/sh

#
# blas_%%gerc.sh
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
TEMPLATE_SEARCH[4]='\${SYM_COMPLEX_TYPE}'
TEMPLATE_SEARCH[5]='\${SYM_CMPLX_DECL}'
TEMPLATE_SEARCH[6]='\${SYM_INTRINSIC_CONJG}'
TEMPLATE_SEARCH[7]='\${SYM_INTRINSIC_CADD}'
TEMPLATE_SEARCH[8]='\${SYM_INTRINSIC_CMUL}'
TEMPLATE_SEARCH[9]='\${SYM_INTRINSIC_CEQ}'
TEMPLATE_SEARCH[10]='\${SYM_INTRINSIC_CNE}'
TEMPLATE_SEARCH[11]='\${SYM_INTRINSIC_IMAX}'
TEMPLATE_SEARCH[12]='\${SYM_CALL_CONJG}'
TEMPLATE_SEARCH[13]='\${SYM_CALL_CADD}'
TEMPLATE_SEARCH[14]='\${SYM_CALL_CMUL}'
TEMPLATE_SEARCH[15]='\${SYM_CALL_CEQ}'
TEMPLATE_SEARCH[16]='\${SYM_CALL_CNE}'
TEMPLATE_SEARCH[17]='\${SYM_CALL_IMAX}'

do_gerc_a ()
{
	local src="${1}"
	local dest="${2}"

	rm -f ${dest}
	cp ${src} ${dest}
	
	declare -a search
	declare -a replace
	
	search[0]='gerc'
	search[1]='GERC'
	search[2]='COMPLEX CFN_D2D(A)'

	replace[0]='gerc_a'
	replace[1]='GERC_A'
	replace[2]='COMPLEX CFN_A2D(A, N)'

	replace_all "${dest}" search[@] replace[@]
}

do_gerc_b ()
{
	local src="${1}"
	local dest="${2}"

	rm -f ${dest}
	cp ${src} ${dest}
	
	declare -a search
	declare -a replace

	search[0]='gerc'
	search[1]='GERC'
	search[2]='COMPLEX CFN_D2D(A)'
	search[3]='A CFN_A2DT (II, J)'

	replace[0]='gerc_b'
	replace[1]='GERC_B'
	replace[2]='COMPLEX CFN_B2D(A)'
	replace[3]='A CFN_B2D_AT (N, II, J)'

	replace_all "${dest}" search[@] replace[@]
}

do_blas_cgerc ()
{
	local dest="${SOURCE_PATH}/blas_cgerc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%gerc.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='c'
	replace[1]='C'
	replace[2]='COMPLEX'
	replace[4]='CFN_COMPLEX'
	replace[5]='CFN_CMPLX_DECL'
	replace[6]='CONJG'
	replace[7]='CADD'
	replace[8]='CMUL'
	replace[9]='CEQ'
	replace[10]='CNE'
	replace[11]='IMAX'
	replace[12]='CFN_CONJG'
	replace[13]='CFN_CADD'
	replace[14]='CFN_CMUL'
	replace[15]='CFN_CEQ'
	replace[16]='CFN_CNE'
	replace[17]='CFN_IMAX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]

	do_gerc_a "${dest}" "${SOURCE_PATH}/blas_cgerc_a.c"
	do_gerc_b "${dest}" "${SOURCE_PATH}/blas_cgerc_b.c"
}

do_blas_bcgerc ()
{
	local dest="${SOURCE_PATH}/blas_bcgerc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%gerc.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='sc'
	replace[1]='SC'
	replace[2]='COMPLEX*8'
	replace[4]='CFN_SCOMPLEX'
	replace[5]='CFN_SCMPLX_DECL'
	replace[6]='SCONJG'
	replace[7]='SCADD'
	replace[8]='SCMUL'
	replace[9]='SCEQ'
	replace[10]='SCNE'
	replace[11]='IMAX'
	replace[12]='CFN_SCONJG'
	replace[13]='CFN_SCADD'
	replace[14]='CFN_SCMUL'
	replace[15]='CFN_SCEQ'
	replace[16]='CFN_SCNE'
	replace[17]='CFN_IMAX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]

	do_gerc_a "${dest}" "${SOURCE_PATH}/blas_bcgerc_a.c"
	do_gerc_b "${dest}" "${SOURCE_PATH}/blas_bcgerc_b.c"
}

do_blas_dcgerc ()
{
	local dest="${SOURCE_PATH}/blas_dcgerc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%gerc.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='dc'
	replace[1]='DC'
	replace[2]='COMPLEX*16'
	replace[4]='CFN_DCOMPLEX'
	replace[5]='CFN_DCMPLX_DECL'
	replace[6]='DCONJG'
	replace[7]='DCADD'
	replace[8]='DCMUL'
	replace[9]='DCEQ'
	replace[10]='DCNE'
	replace[11]='IMAX'
	replace[12]='CFN_DCONJG'
	replace[13]='CFN_DCADD'
	replace[14]='CFN_DCMUL'
	replace[15]='CFN_DCEQ'
	replace[16]='CFN_DCNE'
	replace[17]='CFN_IMAX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]

	do_gerc_a "${dest}" "${SOURCE_PATH}/blas_dcgerc_a.c"
	do_gerc_b "${dest}" "${SOURCE_PATH}/blas_dcgerc_b.c"
}

do_blas_zcgerc ()
{
	local dest="${SOURCE_PATH}/blas_zcgerc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%gerc.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='zc'
	replace[1]='ZC'
	replace[2]='COMPLEX*16'
	replace[4]='CFN_ZCOMPLEX'
	replace[5]='CFN_ZCMPLX_DECL'
	replace[6]='ZCONJG'
	replace[7]='ZCADD'
	replace[8]='ZCMUL'
	replace[9]='ZCEQ'
	replace[10]='ZCNE'
	replace[11]='IMAX'
	replace[12]='CFN_ZCONJG'
	replace[13]='CFN_ZCADD'
	replace[14]='CFN_ZCMUL'
	replace[15]='CFN_ZCEQ'
	replace[16]='CFN_ZCNE'
	replace[17]='CFN_IMAX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]

	do_gerc_a "${dest}" "${SOURCE_PATH}/blas_zcgerc_a.c"
	do_gerc_b "${dest}" "${SOURCE_PATH}/blas_zcgerc_b.c"
}

do_blas_zgerc ()
{
	local dest="${SOURCE_PATH}/blas_zgerc.c"
	declare -r template="${TEMPLATE_PATH}/blas_%%gerc.ctpl"

	declare -a replace

	rm -f ${dest}
	cp ${template} ${dest}

	replace[0]='z'
	replace[1]='Z'
	replace[2]='COMPLEX*16'
	replace[4]='CFN_ZCOMPLEX'
	replace[5]='CFN_ZCMPLX_DECL'
	replace[6]='ZCONJG'
	replace[7]='ZCADD'
	replace[8]='ZCMUL'
	replace[9]='ZCEQ'
	replace[10]='ZCNE'
	replace[11]='IMAX'
	replace[12]='CFN_ZCONJG'
	replace[13]='CFN_ZCADD'
	replace[14]='CFN_ZCMUL'
	replace[15]='CFN_ZCEQ'
	replace[16]='CFN_ZCNE'
	replace[17]='CFN_IMAX'

	replace_all "${dest}" TEMPLATE_SEARCH[@] replace[@]

	do_gerc_a "${dest}" "${SOURCE_PATH}/blas_zgerc_a.c"
	do_gerc_b "${dest}" "${SOURCE_PATH}/blas_zgerc_b.c"
}

main ()
{
	do_blas_cgerc
	do_blas_zgerc
	do_blas_bcgerc
	do_blas_dcgerc
	do_blas_zcgerc

}; main $@

# EOF