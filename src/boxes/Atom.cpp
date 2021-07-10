#include "Atom.h"

Atom::Atom(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : _file(file), _start_offset(start_offset) {
    size = shift_u32();
    box_type = shift_u32_str();

    if (size == 1) {
        uint64_t largesize;
    } else if (size == 0) {
        // box extends to end of file
    }

    if (box_type == "uuid") {
        usertype = shift_u8();
    }
}

Atom::~Atom() {}

uint64_t Atom::shift_u64() {
    uint32_t val = _file->u64_from(_start_offset);
    _start_offset += UINT_64_BYTE_SHIFT_SIZE;
    return val;
}

uint32_t Atom::shift_u32() {
    uint32_t val = _file->u32_from(_start_offset);
    _start_offset += UINT_32_BYTE_SHIFT_SIZE;
    return val;
}

std::string Atom::shift_u32_str() {
    std::string val;
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    return val;
}

uint16_t Atom::shift_u16() {
    uint16_t val = _file->u16_from(_start_offset);
    _start_offset += UINT_16_BYTE_SHIFT_SIZE;
    return val;
}

uint8_t Atom::shift_u8() {
    uint8_t val = _file->u8_from(_start_offset);
    _start_offset += UINT_8_BYTE_SHIFT_SIZE;
    return val;
}

std::string Atom::shift_u8_str() {
    std::string val;
    val.push_back((char)shift_u8());
    return val;
}
