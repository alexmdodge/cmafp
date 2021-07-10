#include <vector>

#include "Atom.h"

// Movie Header Box
// Format Req: 1
//
// Media-independent data for entire presentation
class MovieHeaderBox : public Atom {
   public:
    MovieHeaderBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset);
};
