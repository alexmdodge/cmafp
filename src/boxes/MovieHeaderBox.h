#include <vector>

#include "FullBox.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
class MovieHeaderBox : public FullBox {
   public:
    MovieHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    uint64_t creation_time;
    uint64_t modification_time;
    uint64_t timescale;
    uint64_t duration;
    float rate;
    float volume;
    std::vector<std::string> matrix;
    std::vector<std::string> pre_defined;
    uint32_t next_track_id;
};
