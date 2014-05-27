#!/bin/sh
set -ex
pwd
wget http://luvit.io/dist/latest/luvit-0.7.0.tar.gz
tar xf luvit-0.7.0.tar.gz
cd luvit-0.7.0 && ./configure --prefix=$HOME
#make --silent PREFIX=$HOME
#make install PREFIX=$HOME
#export PATH=$PATH:$HOME/bin