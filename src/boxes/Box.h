#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "MediaFile.h"
#include "json.hpp"

using json = nlohmann::json;

// Box sizes are defined here in bytes, but referenced
// in the spec via bits
const uint32_t BOX_HEADER_BYTE_SIZE = 4;
const uint32_t BOX_HEADER_EXT_BYTE_SIZE = 8;

const uint32_t UINT_8_BYTE_SHIFT_SIZE = 1;
const uint32_t UINT_16_BYTE_SHIFT_SIZE = 2;
const uint32_t UINT_32_BYTE_SHIFT_SIZE = 4;
const uint32_t UINT_64_BYTE_SHIFT_SIZE = 8;

class Box {
   public:
    Box(std::shared_ptr<MediaFile>& file, uint32_t start_offset);
    ~Box();

    json to_json();

    uint64_t shift_u64();
    uint32_t shift_u32();
    std::string shift_u32_str();
    uint16_t shift_u16();
    uint8_t shift_u8();
    std::string shift_u8_str();

    uint32_t size;
    uint64_t large_size;
    std::string box_type;
    std::string user_type;
    uint32_t end_offset;
    std::string box_variation = "standard";

   protected:
    uint32_t _byte_offset;
    std::shared_ptr<MediaFile>& _file;
};
