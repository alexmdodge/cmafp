
#include "Boxes.h"

// Movie Box
// Format Req: 1
//
// Metadata for presentation
void Boxes::moov() {
    uint32_t size = shift_u32();
    std::string box_type = shift_u32_str();

    _reader["MovieBox"] = {};
    _reader["MovieBox"]["size"] = size;
    _reader["MovieBox"]["box_type"] = box_type;
    _reader["MovieBox"]["children"] = 0;

    mvhd();
    // trak();
}
