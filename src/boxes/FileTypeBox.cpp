
#include "FileTypeBox.h"

FileTypeBox::FileTypeBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    major_brand = shift_u32_str();
    minor_version = shift_u32();

    compatible_brands = {};

    while (_byte_offset < size) {
        compatible_brands.push_back(shift_u32_str());
    }
};

json FileTypeBox::to_json() {
    json data = Box::to_json();

    data["major_brand"] = major_brand;
    data["minor_version"] = minor_version;
    data["compatible_brands"] = compatible_brands;

    return data;
};
