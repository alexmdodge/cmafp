#include "FullBox.h"

#include "BinaryHelpers.h"

FullBox::FullBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    version = shift_u8();

    flags += BinaryHelpers::uint8_to_hex_string(shift_u8());
    flags += BinaryHelpers::uint8_to_hex_string(shift_u8(), false);
    flags += BinaryHelpers::uint8_to_hex_string(shift_u8(), false);
};

json FullBox::to_json() {
    json data = Box::to_json();

    data["box_variation"] = box_variation;
    data["version"] = version;
    data["flags"] = flags;

    return data;
}
