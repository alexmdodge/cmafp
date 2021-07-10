
#include <vector>

#include "Atom.h"

// File Type Box
// Format Req: 1
//
// General compatability metadata
class FileTypeBox : public Atom {
   public:
    FileTypeBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    std::string major_brand;
    uint32_t minor_version;
    std::vector<std::string> compatible_brands;
};
