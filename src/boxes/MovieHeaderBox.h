#include <vector>

#include "FullBox.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
class MovieHeaderBox : public FullBox {
   public:
    MovieHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    uint64_t creation_time;
    uint64_t modification_time;
    uint32_t timescale;
    uint64_t duration;
    float rate;
    float volume;
    std::vector<std::string> matrix;
};
