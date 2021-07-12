
#include "MovieHeaderBox.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
MovieHeaderBox::MovieHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : FullBox{file, start_offset} {
    if (version == 1) {
        creation_time = shift_u64();
        modification_time = shift_u64();
        timescale = shift_u32();
        duration = shift_u64();
    } else {  // version == 0
        // Note: casting u32 values into u64 for simplicity
        // of interfacing, but could explicitly shift into smaller
        // variables
        creation_time = shift_u32();
        modification_time = shift_u32();
        timescale = shift_u32();
        duration = shift_u32();
    }

    // template int(32) rate = 0x00010000;  // typically 1.0
    int u16_float_shift = 10000;
    float rate = shift_u16() + (shift_u16() / u16_float_shift);

    // template int(16) volume = 0x0100;    // typically, full volume
    int u8_float_shift = 100;
    uint16_t volume = shift_u8() + (shift_u8() / u8_float_shift);

    // Reserved 16 Bits (2 bytes)
    shift_u8();
    shift_u8();

    // Reserved 2 x UINT32
    shift_u32();
    shift_u32();

    // template int(32)[9] matrix = {0x00010000, 0, 0, 0, 0x00010000, 0, 0, 0, 0x40000000};
    // Unity matrix
    matrix = {};
    int matrix_spec_length = 9;
    for (auto i = 0; i < matrix_spec_length; i++) {
        // matrix.push_back(shift_u32())
    }

    // bit(32)[6] pre_defined = 0;
    uint32_t pre_defined_1 = shift_u32();
    uint32_t pre_defined_2 = shift_u32();
    uint32_t pre_defined_3 = shift_u32();
    uint32_t pre_defined_4 = shift_u32();
    uint32_t pre_defined_5 = shift_u32();
    uint32_t pre_defined_6 = shift_u32();

    uint32_t next_track_id = shift_u32();
};
