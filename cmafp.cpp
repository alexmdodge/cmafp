
#include <emscripten/bind.h>

#include <iostream>
#include <memory>
#include <string>

#include "CmafParser.h"
#include "MediaFileReader.h"

std::string parse_cmaf_header(int id) {
    std::shared_ptr<MediaFile> header_file = MediaFileReader::get_file(id);

    if (header_file->is_invalid()) {
        std::cout << "[CPP] Error parsing header file, invalid file reference" << std::endl;
        return "{ \"error\": \"Error parsing header\"}";
    }

    return CmafParser::parse_header(header_file);
}

EMSCRIPTEN_BINDINGS(cmafp) {
    // File Load Utilities
    emscripten::function("createFile", &MediaFileReader::create_file);
    emscripten::function("appendTo", &MediaFileReader::append_to);
    emscripten::function("closeFile", &MediaFileReader::close_file);

    // Parsing Utilities
    emscripten::function("parseHeader", &parse_cmaf_header);
}
