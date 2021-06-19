#include <memory>
#include <string>
#include <vector>

#include "CmafBoxes.h"

class CmafParser {
   public:
    static void parse_header(std::shared_ptr<MediaFile> file);
    static void parse_segment(std::shared_ptr<MediaFile> file);
};
