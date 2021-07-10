
#include <vector>

#include "Atom.h"

// Movie Box
// Format Req: 1
//
// Metadata for presentation
class MovieBox : public Atom {
   public:
    MovieBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);

    std::vector<std::string> children;
};
