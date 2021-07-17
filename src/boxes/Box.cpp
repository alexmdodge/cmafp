#include "Box.h"

Box::Box(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : _file(file), _byte_offset(start_offset) {
    size = shift_u32();

    box_type = shift_u32_str();
    large_size = 0;
    user_type = "";

    if (size == 1) {
        large_size = shift_u64();
    } else if (size == 0) {
        // box extends to end of file
    }

    if (box_type == "uuid") {
        user_type = shift_u8_str();
    }
}

Box::~Box() {}

json Box::to_json() {
    json data{};
    data["box_type"] = box_type;
    data["box_variation"] = box_variation;

    if (large_size > 0) {
        data["large_size"] = large_size;
    } else {
        data["size"] = size;
    }

    if (user_type.length() > 0) {
        data["user_type"] = user_type;
    }

    return data;
}

uint64_t Box::shift_u64() {
    uint32_t val = _file->u64_from(_byte_offset);
    _byte_offset += UINT_64_BYTE_SHIFT_SIZE;
    end_offset = _byte_offset;
    return val;
}

uint32_t Box::shift_u32() {
    uint32_t val = _file->u32_from(_byte_offset);
    _byte_offset += UINT_32_BYTE_SHIFT_SIZE;
    end_offset = _byte_offset;
    return val;
}

std::string Box::shift_u32_str() {
    std::string val;
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    return val;
}

uint16_t Box::shift_u16() {
    uint16_t val = _file->u16_from(_byte_offset);
    _byte_offset += UINT_16_BYTE_SHIFT_SIZE;
    end_offset = _byte_offset;
    return val;
}

uint8_t Box::shift_u8() {
    uint8_t val = _file->u8_from(_byte_offset);
    _byte_offset += UINT_8_BYTE_SHIFT_SIZE;
    end_offset = _byte_offset;
    return val;
}

std::string Box::shift_u8_str() {
    std::string val;
    val.push_back((char)shift_u8());
    return val;
}
