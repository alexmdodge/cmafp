
#include "Boxes.h"

#include "BinaryHelpers.h"

Boxes::Boxes(std::shared_ptr<MediaFile>& file, json& reader) : _file(file), _byte_offset(0), _reader(reader) {}

Boxes::~Boxes() {}

uint64_t Boxes::shift_u64() {
    uint32_t val = _file->u64_from(_byte_offset);
    _byte_offset += UINT_64_BYTE_SHIFT_SIZE;
    return val;
}

uint32_t Boxes::shift_u32() {
    uint32_t val = _file->u32_from(_byte_offset);
    _byte_offset += UINT_32_BYTE_SHIFT_SIZE;
    return val;
}

std::string Boxes::shift_u32_str() {
    std::string val;
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    return val;
}

uint16_t Boxes::shift_u16() {
    uint16_t val = _file->u16_from(_byte_offset);
    _byte_offset += UINT_16_BYTE_SHIFT_SIZE;
    return val;
}

uint8_t Boxes::shift_u8() {
    uint8_t val = _file->u8_from(_byte_offset);
    _byte_offset += UINT_8_BYTE_SHIFT_SIZE;
    return val;
}
