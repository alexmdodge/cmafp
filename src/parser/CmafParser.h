#include <memory>
#include <string>
#include <vector>

#include "Boxes.h"
#include "json.hpp"

using json = nlohmann::json;

class CmafParser {
   public:
    static std::string parse_header(std::shared_ptr<MediaFile>& file);
    static std::string parse_segment(std::shared_ptr<MediaFile>& file);
};
