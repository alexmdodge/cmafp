#include "MediaHeaderBox.h"

#include "BinaryHelpers.h"

MediaHeaderBox::MediaHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : FullBox{file, start_offset} {
    if (version == 1) {
        creation_time = shift_u64();
        modification_time = shift_u64();
        timescale = shift_u32();
        duration = shift_u64();
    } else {  // version==0
        // Note: casting u32 values into u64 for simplicity
        // of interfacing, but could explicitly shift into smaller
        // types
        creation_time = shift_u32();
        modification_time = shift_u32();
        timescale = shift_u32();
        duration = shift_u32();
    }

    // Language code manipulation requires individual bit shifting.
    // Starting with the full 16 bit block
    //
    // Of the 16 bits, the structure is as follows:
    //
    // 0 00000 00000 00000
    // |-> First bit is padding
    //   |---|
    //       |-> Second block, and sequential blocks are 5 bit sections
    //           representing int
    std::bitset<16> source_block = std::bitset<16>(shift_u16());

    // Language chars are stored as differences between their ASCII value
    // and this offset base.
    uint8_t ascii_offset_base = 0x60;

    // Use a full byte which will get converted to a char
    std::vector<std::bitset<8>> target_blocks = {std::bitset<8>(0x0), std::bitset<8>(0x0), std::bitset<8>(0x0)};

    // Start at 14 (zero-indexed) to account for spec offset padding bit. Bit ordering
    // in Bitset is most important to least important.
    int source_index = 14;

    for (auto target : target_blocks) {
        for (auto i = 0; i < 5; i++) {
            target[i] = source_block[source_index];
            source_index--;
        }
        language.push_back((char)((uint8_t)target.to_ulong() + ascii_offset_base));
    }

    pre_defined = shift_u16();
};

json MediaHeaderBox::to_json() {
    json data = Box::to_json();

    data["creation_time"] = creation_time;
    data["modification_time"] = modification_time;
    data["timescale"] = timescale;
    data["duration"] = duration;
    data["language"] = language;
    data["pre_defined"] = pre_defined;

    return data;
}
