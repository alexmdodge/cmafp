
#include <vector>

#include "Box.h"

// Media Box
// Format Req: 1
//
// Declares all information about the media data within the track.
class MediaBox : public Box {
   public:
    MediaBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    // clang-format off

    // NL 3 Boxes
    json mdhd;  // Format Req: 1
    json hdlr;  // Format Req: 1
    json elng;  // Format Req: 0/1
    json minf;  // Format Req: 1

    // NL 4 Boxes
    json vmhd;  // Format Req: CR
    json smhd;  // Format Req: CR
    json sthd;  // Format Req: CR
    json dinf;  // Format Req: 1

    // NL 5 Boxes
    json dref;  // Format Req: 1

    // NL 4 Boxes
    json stbl;  // Format Req: 1

    // NL 5 Boxes
    json stsd;  // Format Req: 1
    json stts;  // Format Req: 1
    json stsc;  // Format Req: 1

    json stsz;  // Format Req: 1
    json stsz2;

    json stco;  // Format Req: 1
    json sgpd;  // Format Req: CR
    json stss;  // Format Req: CR

    // clang-format on

    std::vector<json> children;
};
