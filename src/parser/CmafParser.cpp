#include "CmafParser.h"

#include <iostream>

/*
 * Sequentially parses all required, optional, and conditional boxes
 * as defined in the CMAF/ISOBMFF specifications.
 *
 * CMAF Header order and structure obtained from ISO/IEC 23000-19
 * section 7.3.1 Table 3
 */
std::string CmafParser::parse_header(std::shared_ptr<MediaFile>& media_file) {
    // Each box operation will shift the corresponding offset
    // pointers. Internally these box parsers will contain
    // specific knowledge about their Format Requirements as defined
    // in ISO/IEC 23000-19 section 7.3.1.
    //
    // Boxes with children will parse in a nested manner.
    json reader;
    Boxes boxes(media_file, reader);

    boxes.ftyp();  // Format Req: 1
    // boxes.moov();  // Format Req: 1

    return reader.dump();
}

std::string CmafParser::parse_segment(std::shared_ptr<MediaFile>& file) {
    return "{\"error\": \"Segment parser not yet implemented\"}";
}
