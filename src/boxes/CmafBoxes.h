#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "MediaFile.h"

// Box sizes are defined here in bytes, but referenced
// in the spec via bits
const uint32_t BOX_HEADER_BYTE_SIZE = 4;
const uint32_t BOX_HEADER_EXT_BYTE_SIZE = 8;

struct CmafBoxes {
    CmafBoxes();
    ~CmafBoxes();
    void from(std::shared_ptr<MediaFile> file);

    // Box Spec Parsers
    void ftype();

    // Shared Box Parsing Data
    uint32_t byte_offset;
    uint8_t bit_offset;
    std::shared_ptr<MediaFile> file;
};
