
#include <vector>

#include "FullBox.h"

// Media Header Box
// Format Req: 1
//
// Declares overall information that is media-independent.
class MediaHeaderBox : public FullBox {
   public:
    MediaHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    uint64_t creation_time;
    uint64_t modification_time;
    uint32_t timescale;
    uint64_t duration;

    std::string language;
    uint16_t pre_defined;
};
