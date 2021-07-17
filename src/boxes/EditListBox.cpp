
#include "EditListBox.h"

EditListBox::EditListBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : FullBox{file, start_offset} {
    // TODO: Finish box implementation exposing this as a vector
    // of entries
    uint32_t entry_count = shift_u32();

    for (auto i = 1; i <= entry_count; i++) {
        if (version == 1) {
            uint64_t segment_duration = shift_u64();
            uint64_t media_time = shift_u64();
        } else {  // version==0
            uint32_t segment_duration = shift_u32();
            int32_t media_time = shift_u32();
        }
        int16_t media_rate_integer = shift_u16();
        int16_t media_rate_fraction = shift_u16();
    }
};

json EditListBox::to_json() {
    json data = Box::to_json();

    data["_note"] = "This box has not yet been implented";

    return data;
}
