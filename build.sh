#!/bin/bash

source ../../scripts/utils.sh

SCRIPT_DIR="$( cd "$( dirname "$BASH_SOURCE0]}" )" &> /dev/null && pwd )"

LIB_DIR="$SCRIPT_DIR/lib/cmafp"
LIB_JS="$SCRIPT_DIR/cmafp.js"

# Clean previous build
rm -rf $LIB_DIR
rm $LIB_JS

# Create the library directory and build using the cmake wrapper
mkdir -p $LIB_DIR
cd $LIB_DIR
emcmake cmake ../..
emmake make

# Attach binds in static lib to output JS
cd $SCRIPT_DIR
emcc \
  -Isrc/reader -Isrc/builder -Isrc/helpers -Isrc/parser -Isrc/boxes \
  --bind cmafp.cpp lib/cmafp/libcmafp.a \
  -o cmafp.js
