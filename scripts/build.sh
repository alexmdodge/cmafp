#!/bin/bash


SCRIPT_DIR="$( cd "$( dirname "$BASH_SOURCE0]}" )" &> /dev/null && pwd )"
source "${SCRIPT_DIR}/utils.sh"

REPO_ROOT="$SCRIPT_DIR/.."
OUTPUT_VAL="console.log(require('${REPO_ROOT}/package.json').config.cmafp"

DIR_BASE=$(node -e "${OUTPUT_VAL}.libDir)")
LIB_NAME=$(node -e "${OUTPUT_VAL}.lib)")
LIB_DIR="$REPO_ROOT/${DIR_BASE}"

echo "LIB DIR ${LIB_DIR}"

CPP_BASE=$(node -e "${OUTPUT_VAL}.input)")
WASM_BASE=$(node -e "${OUTPUT_VAL}.output)")
WASM_OUTPUT="${REPO_ROOT}/${WASM_BASE}"

# Create the library directory and build using the cmake wrapper
mkdir -p $LIB_DIR
cd $LIB_DIR

emcmake cmake $REPO_ROOT
emmake make

# Attach binds in static lib to output JS
cd $REPO_ROOT
emcc \
  -Isrc/reader -Isrc/builder -Isrc/helpers -Isrc/parser -Isrc/boxes \
  --bind $CPP_BASE $LIB_DIR/$LIB_NAME \
  -o $WASM_OUTPUT
