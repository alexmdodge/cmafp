
#include "FileTypeBox.h"

FileTypeBox::FileTypeBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Atom{file, start_offset} {
    major_brand = shift_u32_str();
    minor_version = shift_u32();

    compatible_brands = {};

    while (_start_offset < size) {
        compatible_brands.push_back(shift_u32_str());
    }
};
