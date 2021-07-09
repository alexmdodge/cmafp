
#include "Boxes.h"

// File Type Box
// Format Req: 1
//
// General compatability metadata
void Boxes::ftyp() {
    uint32_t size = shift_u32();
    std::string box_type = shift_u32_str();

    // TODO: Manage box inheritance properties
    // if (size == 1) {
    //    uint64_t largesize;
    //} else if (size == 0) {
    //    // box extends to end of file
    //}

    // if (box_type == "uuid") {
    //    uint8_t usertype;  // = extended_type
    //}

    std::string major_brand = shift_u32_str();
    uint32_t minor_version = shift_u32();

    std::vector<std::string> compatible_brands;
    while (_byte_offset < size) {
        compatible_brands.push_back(shift_u32_str());
    }

    _reader["FileTypeBox"] = {};
    _reader["FileTypeBox"]["size"] = size;
    _reader["FileTypeBox"]["box_type"] = box_type;
    _reader["FileTypeBox"]["major_brand"] = major_brand;
    _reader["FileTypeBox"]["minor_version"] = minor_version;
    _reader["FileTypeBox"]["compatible_brands"] = compatible_brands;
}
