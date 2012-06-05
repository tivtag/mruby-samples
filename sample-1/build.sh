#!/bin/bash
conf=debug
proj=mruby-test

# gen make files
premake4 gmake

rm -r bin/$conf/$proj
make -C build config=$conf $proj

# start
bin/$conf/$proj

# note
# chmod 775 build.sh
