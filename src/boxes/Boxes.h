#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "FileTypeBox.h"
#include "MediaFile.h"
#include "MovieBox.h"
#include "json.hpp"

using json = nlohmann::json;

class Boxes {
   public:
    Boxes(std::shared_ptr<MediaFile>& file);
    ~Boxes();

    std::string to_json_str();

    // NL 0 Boxes
    json ftyp;  // Format Req: 1
    json moov;  // Format Req: 1

   private:
    uint32_t _byte_offset;
    std::shared_ptr<MediaFile>& _file;
};
