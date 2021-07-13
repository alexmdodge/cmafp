#include "FullBox.h"

#include "BinaryHelpers.h"

FullBox::FullBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    std::cout << "[FullBox] Offset: " << _byte_offset << std::endl;

    version = shift_u8();

    std::cout << "[FullBox] Post Version: " << _byte_offset << std::endl;

    flags += BinaryHelpers::uint8_to_hex_string(shift_u8());
    flags += BinaryHelpers::uint8_to_hex_string(shift_u8(), false);
    flags += BinaryHelpers::uint8_to_hex_string(shift_u8(), false);

    std::cout << "[FullBox] Offset post flags: " << _byte_offset << std::endl;
};

json FullBox::to_json() {
    json data = Box::to_json();

    data["box_variation"] = box_variation;
    data["version"] = version;
    data["flags"] = flags;

    return data;
}
