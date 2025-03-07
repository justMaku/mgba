#!/bin/sh
set -e
if [ $TRAVIS_OS_NAME = "osx" ]; then
	brew update
	brew install qt5 ffmpeg imagemagick sdl2 libedit libelf libpng libzip
else
	sudo apt-get update
	sudo apt-get -y install libseccomp2
fi
