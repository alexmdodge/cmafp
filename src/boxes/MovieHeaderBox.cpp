
#include "Boxes.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
void Boxes::mvhd() {
    // Extends Full Box
    uint32_t size = shift_u32();
    std::string box_type = shift_u32_str();

    uint8_t version = shift_u8();

    _reader["MovieHeaderBox"]["size"] = size;
    _reader["MovieHeaderBox"]["box_type"] = box_type;
    _reader["MovieHeaderBox"]["version"] = version;

    // TODO: Merge flag binaries as bits
    uint8_t flag_1 = shift_u8();
    uint8_t flag_2 = shift_u8();
    uint8_t flag_3 = shift_u8();

    if (version == 1) {
        uint64_t creation_time = shift_u64();
        uint64_t modification_time = shift_u64();
        uint32_t timescale = shift_u32();
        uint64_t duration = shift_u64();

        _reader["MovieHeaderBox"]["creation_time"] = creation_time;
        _reader["MovieHeaderBox"]["modification_time"] = modification_time;
        _reader["MovieHeaderBox"]["timescale"] = timescale;
        _reader["MovieHeaderBox"]["duration"] = duration;
    } else {  // version == 0
        uint32_t creation_time = shift_u32();
        uint32_t modification_time = shift_u32();
        uint32_t timescale = shift_u32();
        uint32_t duration = shift_u32();

        _reader["MovieHeaderBox"]["creation_time"] = creation_time;
        _reader["MovieHeaderBox"]["modification_time"] = modification_time;
        _reader["MovieHeaderBox"]["timescale"] = timescale;
        _reader["MovieHeaderBox"]["duration"] = duration;
    }

    // template int(32) rate = 0x00010000;  // typically 1.0
    uint32_t rate = shift_u32();

    // template int(16) volume = 0x0100;    // typically, full volume
    uint16_t volume = shift_u16();

    _reader["MovieHeaderBox"]["rate"] = rate;
    _reader["MovieHeaderBox"]["volume"] = volume;

    // const bit(16) reserved = 0;
    // TODO: Merge binaries as bits
    uint8_t reserved_1 = shift_u8();
    uint8_t reserved_2 = shift_u8();

    // const unsigned int(32)[2] reserved = 0;
    uint32_t reserved_3 = shift_u32();
    uint32_t reserved_4 = shift_u32();

    // template int(32)[9] matrix = {0x00010000, 0, 0, 0, 0x00010000, 0, 0, 0, 0x40000000};
    uint32_t u_matrix_1 = shift_u32();
    uint32_t u_matrix_2 = shift_u32();
    uint32_t u_matrix_3 = shift_u32();
    uint32_t u_matrix_4 = shift_u32();
    uint32_t u_matrix_5 = shift_u32();
    uint32_t u_matrix_6 = shift_u32();
    uint32_t u_matrix_7 = shift_u32();
    uint32_t u_matrix_8 = shift_u32();
    uint32_t u_matrix_9 = shift_u32();
    // Unity matrix

    // bit(32)[6] pre_defined = 0;
    uint32_t pre_defined_1 = shift_u32();
    uint32_t pre_defined_2 = shift_u32();
    uint32_t pre_defined_3 = shift_u32();
    uint32_t pre_defined_4 = shift_u32();
    uint32_t pre_defined_5 = shift_u32();
    uint32_t pre_defined_6 = shift_u32();

    uint32_t next_track_id = shift_u32();

    _reader["MovieHeaderBox"]["next_track_id"] = next_track_id;

    _reader["MovieHeaderBox"]["parent"] = "MovieBox";

    int childCount = _reader["MovieBox"]["children"];
    _reader["MovieBox"]["children"] = childCount + 1;
}
