
#include "TrackHeaderBox.h"

#include <iostream>

#include "BinaryHelpers.h"

TrackHeaderBox::TrackHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : FullBox{file, start_offset} {
    // TODO: Parse additional variations of flags
    if (flags == "0x000007") {
        track_enabled = true;
        track_in_movie = true;
        track_in_preview = true;
    }

    if (version == 1) {
        creation_time = shift_u64();
        modification_time = shift_u64();
        track_id = shift_u32();

        // Reserved UINT32
        shift_u32();

        duration = shift_u64();
    } else {  // version == 0
        // Note: casting u32 values into u64 for simplicity
        // of interfacing, but could explicitly shift into smaller
        // types
        creation_time = shift_u32();
        modification_time = shift_u32();
        track_id = shift_u32();

        // Reserved UINT32
        shift_u32();

        duration = shift_u32();
    }

    // Reserved 2 x UINT32
    shift_u32();
    shift_u32();

    layer = (int16_t)shift_u16();
    alternate_group = (int16_t)shift_u16();

    int u8_float_shift = 100;
    volume = shift_u8() + (shift_u8() / u8_float_shift);

    // Reserved 16 Bits (2 bytes)
    shift_u16();

    matrix = {};
    int matrix_spec_length = 9;
    for (auto i = 0; i < matrix_spec_length; i++) {
        matrix.push_back(BinaryHelpers::uint32_to_hex_string(shift_u32()));
    }

    float u16_float_shift = 10000;
    width = (float)shift_u16() + ((float)shift_u16() / u16_float_shift);
    height = (float)shift_u16() + ((float)shift_u16() / u16_float_shift);
};

json TrackHeaderBox::to_json() {
    json data = FullBox::to_json();

    data["creation_time"] = creation_time;
    data["modification_time"] = modification_time;
    data["track_id"] = track_id;
    data["track_enabled"] = track_enabled;
    data["track_in_movie"] = track_in_movie;
    data["track_in_preview"] = track_in_preview;
    data["track_size_is_aspect_ratio"] = track_size_is_aspect_ratio;
    data["duration"] = duration;
    data["layer"] = layer;
    data["alternate_group"] = alternate_group;
    data["volume"] = volume;
    data["matrix"] = matrix;
    data["width"] = width;
    data["height"] = height;

    return data;
}
