#include <memory>
#include <string>
#include <vector>

#include "MediaFile.h"

class MediaFileReader {
   public:
    static int create_file(std::string name, size_t size);
    static void append_to(int id, uint8_t value);
    static std::string close_file(int id);
    static std::shared_ptr<MediaFile> get_file(int id);

   private:
    static std::vector<std::shared_ptr<MediaFile>> files;
};
