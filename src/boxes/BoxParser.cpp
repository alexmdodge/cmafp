
#include "BoxParser.h"

#include "BinaryHelpers.h"

BoxParser::BoxParser(std::shared_ptr<MediaFile>& file) : _file(file), _byte_offset(0) {}

BoxParser::~BoxParser() {}

uint32_t BoxParser::shift_u32() {
    uint32_t val = _file->u32_from(_byte_offset);
    _byte_offset += UINT_32_BYTE_SHIFT_SIZE;
    return val;
}

std::string BoxParser::shift_u32_str() {
    std::string val;
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    val.push_back((char)shift_u8());
    return val;
}

uint16_t BoxParser::shift_u16() {
    uint16_t val = _file->u16_from(_byte_offset);
    _byte_offset += UINT_16_BYTE_SHIFT_SIZE;
    return val;
}

uint8_t BoxParser::shift_u8() {
    uint8_t val = _file->u8_from(_byte_offset);
    _byte_offset += UINT_8_BYTE_SHIFT_SIZE;
    return val;
}

void print_char_list(std::vector<char>& list) {
    for (auto val : list) {
        std::cout << val;
    }
}

template <typename T>
void print(std::string key, T val, int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "\t";
    }

    std::cout << key << ": " << std::to_string(val) << std::endl;
}

void print(std::string msg, int depth) {
    for (int i = 0; i < depth; i++) {
        std::cout << "\t";
    }

    std::cout << msg << std::endl;
}

void BoxParser::ftype() {
    uint32_t size = shift_u32();
    std::string box_type = shift_u32_str();

    std::string major_brand = shift_u32_str();
    uint32_t minor_version = shift_u32();

    std::vector<std::string> compatible_brands;
    while (_byte_offset < size) {
        compatible_brands.push_back(shift_u32_str());
    }

    print("ftype", 1);
    print("size", size, 2);
    print("box_type: " + box_type, 2);
    print("major_brand: " + major_brand, 2);
    print("minor_version", minor_version, 2);
    print("compatible_brands:", 2);
    for (auto brand : compatible_brands) {
        print(brand, 3);
    }

    std::cout << std::endl;
}
