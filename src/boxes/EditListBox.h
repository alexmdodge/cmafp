
#include <vector>

#include "FullBox.h"

// Edit List Box
// Format Req: 1
//
// Only box present in Edit Box. See that box definition for more info.
class EditListBox : public FullBox {
   public:
    EditListBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();
};
