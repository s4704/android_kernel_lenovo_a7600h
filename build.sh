#!/bin/bash
#export KBUILD_BUILD_USER=
#export KBUILD_BUILD_HOST=
export CROSS_COMPILE=/home/s4704/android-dev/kernel/a7600/arm-linux-androideabi-4.8/bin/arm-linux-androideabi-
#export USE_CCACHE=1
export ARCH=arm ARCH_MTK_PLATFORM=mt6582
export TARGET=out
if ! [ -d $TARGET ];then mkdir $TARGET;fi
if ! [ -f $TARGET/.config ];then make O=$TARGET ARCH=$ARCH a7600h_defconfig;fi
make O=$TARGET ARCH=$ARCH $1 $2
