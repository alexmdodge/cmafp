#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "MediaFile.h"

// Box sizes are defined here in bytes, but referenced
// in the spec via bits
const uint32_t BOX_HEADER_BYTE_SIZE = 4;
const uint32_t BOX_HEADER_EXT_BYTE_SIZE = 8;

const uint32_t UINT_8_BYTE_SHIFT_SIZE = 1;
const uint32_t UINT_16_BYTE_SHIFT_SIZE = 2;
const uint32_t UINT_32_BYTE_SHIFT_SIZE = 4;

class BoxParser {
   public:
    BoxParser(std::shared_ptr<MediaFile>& file);
    ~BoxParser();

    uint32_t shift_u32();
    std::string shift_u32_str();
    uint16_t shift_u16();
    uint8_t shift_u8();

    // Box Spec Parsers
    void ftype();

   private:
    uint32_t _byte_offset;
    std::shared_ptr<MediaFile>& _file;
};
