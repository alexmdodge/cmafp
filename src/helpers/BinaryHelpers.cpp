#include "BinaryHelpers.h"

#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>

std::string BinaryHelpers::uint8_to_hex_string(const uint8_t& value, bool with_prefix) {
    std::stringstream stream;

    stream << std::hex << std::setfill('0');
    stream << std::hex << std::setw(2) << static_cast<int>(value);

    if (with_prefix) {
        return "0x" + stream.str();
    } else {
        return stream.str();
    }
}

std::string BinaryHelpers::uint32_to_hex_string(const uint32_t& value, bool with_prefix) {
    std::stringstream stream;

    stream << std::hex << std::setfill('0');
    stream << std::hex << std::setw(8) << static_cast<int>(value);

    if (with_prefix) {
        return "0x" + stream.str();
    } else {
        return stream.str();
    }
}

std::string BinaryHelpers::uint8_to_binary_string(const uint8_t& value) {
    return std::bitset<8>(value).to_string();
}

std::string BinaryHelpers::uint16_to_binary_string(const uint16_t& value) {
    return std::bitset<16>(value).to_string();
}

std::string BinaryHelpers::uint32_to_binary_string(const uint32_t& value) {
    return std::bitset<32>(value).to_string();
}
