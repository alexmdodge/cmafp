
#include <vector>

#include "Box.h"

// Edit Box
// Format Req: CR
//
// Maps the presentation time of media. For CMAF it contains a single
// EditListBox which either notifies of adjustments to the earliest
// video sample for earlier spec TrackRunBoxes or notifies of an offset
// between the presentation time and composition time.
class EditBox : public Box {
   public:
    EditBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    // clang-format off

    // NL 3 Boxes
    json elst;  // Format Req: 1

    // clang-format on

    bool is_present = false;
    std::vector<json> children;
};
