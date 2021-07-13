#pragma once

#include <string>

#include "Box.h"
#include "MediaFile.h"

class FullBox : public Box {
   public:
    FullBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    uint8_t version;
    std::string flags;
    std::string box_variation = "full";
};
