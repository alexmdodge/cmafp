#include "CmafParser.h"

#include <iostream>

/*
 * Sequentially parses all required, optional, and conditional boxes
 * as defined in the CMAF/ISOBMFF specifications.
 *
 * CMAF Header order and structure obtained from ISO/IEC 23000-19
 * section 7.3.1 Table 3
 */
void CmafParser::parse_header(std::shared_ptr<MediaFile>& file) {
    std::cout << "[CPP] Parsing Header: " << file->name() << std::endl;

    // Each box operation will shift the corresponding offset
    // pointers. Internally these box parsers will contain
    // specific knowledge about their Format Requirements as defined
    // in ISO/IEC 23000-19 section 7.3.1
    BoxParser parser(file);

    std::cout << std::endl;
    std::cout << "[CPP] - - - - - Header Boxes - - - - - - - - - -" << std::endl;
    std::cout << std::endl;

    parser.ftype();  // Format Req: 1
}

void CmafParser::parse_segment(std::shared_ptr<MediaFile>& file) {
    std::cout << "[CPP] Segment Parsed" << std::endl;
}
