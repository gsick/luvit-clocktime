#!/bin/sh
set -ex
wget http://luvit.io/dist/latest/luvit-0.7.0.tar.gz
tar xf luvit-0.7.0.tar.gz
cd luvit-0.7.0 && ./configure --prefix=/usr && make --silent PREFIX=/usr && make install PREFIX=/usr

