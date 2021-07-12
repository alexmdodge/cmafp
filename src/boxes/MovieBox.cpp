
#include "MovieBox.h"

MovieBox::MovieBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    children = {};
};

json MovieBox::to_json() {
    json data = Box::to_json();
    data["children"] = children;

    return data;
}
