# WASM CMAF Parser

A WASM wrapped CMAF parser conforming to the ISO/IEC 23000-19 and 14496-12 specifications for CMAF and ISOBMFF.

# Setup

The following tools are required to build this project:
* Node (Minimum v12)
* CMake (Minimum v3.20.2)
* Emscripten (Latest)

# Install

To build, run, and test the parser:

```sh
npm install
npm run build
npm test
```

# Testing

Tests are located in the `test` directory and include sample HLS and DASH wrapped CMAF media objects.
