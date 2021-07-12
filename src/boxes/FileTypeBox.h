
#include <vector>

#include "Box.h"

// File Type Box
// Format Req: 1
//
// General compatability metadata
class FileTypeBox : public Box {
   public:
    FileTypeBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    json to_json();

    std::string major_brand;
    uint32_t minor_version;
    std::vector<std::string> compatible_brands;
};
