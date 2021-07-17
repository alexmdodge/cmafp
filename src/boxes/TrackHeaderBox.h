
#include <vector>

#include "FullBox.h"

// Track Header Box
// Format Req: 1
//
// Outlines structure and metadata of a single track.
class TrackHeaderBox : public FullBox {
   public:
    TrackHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    uint64_t creation_time;
    uint64_t modification_time;
    uint32_t track_id;
    uint64_t duration;

    bool track_enabled = false;
    bool track_in_movie = false;
    bool track_in_preview = false;
    bool track_size_is_aspect_ratio = false;

    int16_t layer;
    int16_t alternate_group;
    float volume;
    std::vector<std::string> matrix;

    float width;
    float height;
};
