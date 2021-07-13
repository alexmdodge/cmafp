
#include <vector>

#include "FullBox.h"

// Track Header Box
// Format Req: 1
//
// Outlines structure and metadata of a single track.
class TrackHeaderBox : public FullBox {
   public:
    TrackHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    uint64_t creation_time;
    uint64_t modification_time;
    uint64_t duration;
    uint32_t track_id;

    uint16_t layer;
    uint16_t alternate_group;
    float volume;
    std::vector<std::string> matrix;

    float width;
    float height;

    json to_json();
};
