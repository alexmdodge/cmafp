
#include "MovieHeaderBox.h"

#include "BinaryHelpers.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
MovieHeaderBox::MovieHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : FullBox{file, start_offset} {
    std::cout << "[MovieHeaderBox] type: " << box_type << std::endl;
    std::cout << "[MovieHeaderBox] offset start: " << _byte_offset << std::endl;

    if (version == 1) {
        // creation_time = shift_u64();
        // modification_time = shift_u64();
        // timescale = shift_u32();
        // duration = shift_u64();
    } else {  // version == 0
        // Note: casting u32 values into u64 for simplicity
        // of interfacing, but could explicitly shift into smaller
        // variables
        creation_time = shift_u32();
        modification_time = shift_u32();
        timescale = shift_u32();
        duration = shift_u32();
    }

    std::cout << "[MovieHeaderBox] post initials: " << _byte_offset << std::endl;

    int u16_float_shift = 10000;
    rate = shift_u16() + (shift_u16() / u16_float_shift);

    int u8_float_shift = 100;
    volume = shift_u8() + (shift_u8() / u8_float_shift);

    // Reserved 16 Bits (2 bytes)
    shift_u8();
    shift_u8();

    // Reserved 2 x unsigned
    shift_u32();
    shift_u32();

    matrix = {};
    int matrix_spec_length = 9;
    for (auto i = 0; i < matrix_spec_length; i++) {
        matrix.push_back(BinaryHelpers::uint32_to_hex_string(shift_u32()));
    }

    pre_defined = {};
    int pre_defined_length = 6;
    for (auto i = 0; i < pre_defined_length; i++) {
        pre_defined.push_back(BinaryHelpers::uint32_to_hex_string(shift_u32()));
    }

    next_track_id = shift_u32();
};

json MovieHeaderBox::to_json() {
    json data = FullBox::to_json();

    data["creation_time"] = creation_time;
    data["modification_time"] = modification_time;
    data["timescale"] = timescale;
    data["duration"] = duration;
    data["rate"] = rate;
    data["volume"] = volume;
    data["matrix"] = matrix;
    data["pre_defined"] = pre_defined;
    data["next_track_id"] = next_track_id;

    return data;
}
