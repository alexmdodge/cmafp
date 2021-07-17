
#include <vector>

#include "Box.h"

// Track Box
// Format Req: 1
//
// Container box for single track of presentation. Contains either media
// data, or hinting metadata
class TrackBox : public Box {
   public:
    TrackBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    // clang-format off

    // NL 2 Boxes
    json tkhd;  // Format Req: 1
    json edts;  // Format Req: CR
    json mdia;  // Format Req: 1

    // NL 2 Boxes
    json udta;  // Format Req: 0/1

    // NL 3 Boxes
    json cprt;  // Format Req: *
    json kind;  // Format Req: *

    // NL 2 Boxes
    json mehd;  // Format Req: 0/1
    json trex;  // Format Req: 1

    // clang-format on

    std::vector<json> children;
};
