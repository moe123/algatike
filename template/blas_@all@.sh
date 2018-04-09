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

LOCAL_PATH=$(abspath ${0})
TEMPLATE_PATH=${LOCAL_PATH}/template

main ()
{
	sh ${TEMPLATE_PATH}/blas_%%abs1.sh
	sh ${TEMPLATE_PATH}/blas_%%axpy.sh
	sh ${TEMPLATE_PATH}/blas_%%copy.sh
	sh ${TEMPLATE_PATH}/blas_%%dotc.sh
	sh ${TEMPLATE_PATH}/blas_%%dotu.sh
	sh ${TEMPLATE_PATH}/blas_%%gerc.sh
}; main $@

# EOF