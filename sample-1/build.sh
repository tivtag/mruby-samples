#!/bin/bash
conf=debug
proj=mruby-sample-1

# gen make files
premake4 gmake

rm -r bin/$conf/$proj
make -C build config=$conf $proj

# start
bin/$conf/$proj

