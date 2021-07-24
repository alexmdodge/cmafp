# WASM CMAF Parser

A WASM wrapped CMAF parser conforming to the ISO/IEC 23000-19 and 14496-12 specifications for CMAF and ISOBMFF.

## Setup

The following tools are required to build this project:
* Node (Minimum v12)
* CMake (Minimum v3.20.2)
* Emscripten (Latest)

## Install

To build, run, and test the parser using the default WASM approach:

```sh
npm install
npm run build
npm test
```

## Testing

Tests are located in the `test` directory and include sample HLS and DASH wrapped CMAF media objects.

## Parsing Support

The following CMAF header boxes are supported:

- [x] ftyp
- [x] moov
- [x] mvhd
- [x] trak
- [x] tkhd
- [x] edts
- [x] elst
- [x] mdia
- [x] mdhd
- [ ] hdlr
- [ ] elng
- [ ] minf
- [ ] vmhd
- [ ] smhd
- [ ] sthd 
- [ ] dinf
- [ ] dref
- [ ] stbl
- [ ] stsd
- [ ] stts
- [ ] stsc
- [ ] stsz/stz2
- [ ] stco
- [ ] sgpd
- [ ] stss
- [ ] udta
- [ ] cprt
- [ ] kind
- [ ] mvex
- [ ] mehd
- [ ] trex
- [ ] pssh
- [ ] stsd
- [ ] sinf
- [ ] frma
- [ ] schm
- [ ] schi
- [ ] tenc

The following CMAF chunk, fragment, and segment boxes are supported:

- [ ] styp
- [ ] prft
- [ ] emsg
- [ ] moof
- [ ] mfhd
- [ ] traf
- [ ] tfhd
- [ ] tfdt
- [ ] trun
- [ ] senc
- [ ] saio
- [ ] saiz
- [ ] sbgp
- [ ] sgpd
- [ ] subs
- [ ] mdat
