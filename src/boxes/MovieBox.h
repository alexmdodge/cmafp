
#include <vector>

#include "Box.h"

// Movie Box
// Format Req: 1
//
// Metadata for presentation
class MovieBox : public Box {
   public:
    MovieBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    // clang-format off

    // NL 1 Boxes
    json mvhd;  // Format Req: 1
    json trak;  // Format Req: 1

    // NL 1 Boxes
    json mvex;  // Format Req: 1

    // NL 1 Boxes
    json pssh;  // Format Req: *

    // clang-format on

    std::vector<json> children;
};
