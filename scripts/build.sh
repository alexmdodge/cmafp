#!/bin/bash

source ./scripts/utils.sh

SCRIPT_DIR="$( cd "$( dirname "$BASH_SOURCE0]}" )" &> /dev/null && pwd )"

REPO_ROOT="$SCRIPT_DIR/.."

DIR_BASE=$(node -e "require('${REPO_ROOT}/package.json').config.cmafp.libDir")
LIB_NAME=$(node -e "require('${REPO_ROOT}/package.json').config.cmafp.lib")
LIB_DIR="$SCRIPT_DIR/${DIR_BASE}"

CPP_BASE=$(node -e "require('${REPO_ROOT}/package.json').config.cmafp.intput")
WASM_BASE=$(node -e "require('${REPO_ROOT}/package.json').config.cmafp.output")
WASM_OUTPUT="${SCRIPT_DIR}/${WASM_BASE}"

# Clean previous build
#rm -rf $LIB_DIR
#rm $LIB_OUTPUT

# Create the library directory and build using the cmake wrapper
mkdir -p $LIB_DIR
cd $LIB_DIR
emcmake cmake $REPO_ROOT
emmake make

# Attach binds in static lib to output JS
cd $SCRIPT_DIR
emcc \
  -Isrc/reader -Isrc/builder -Isrc/helpers -Isrc/parser -Isrc/boxes \
  --bind $CPP_BASE $LIB_DIR/$LIB_BASE \
  -o $WASM_OUTPUT
