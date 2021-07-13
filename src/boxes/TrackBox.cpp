
#include "TrackBox.h"

TrackBox::TrackBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    children = {};
};

json TrackBox::to_json() {
    json data = Box::to_json();

    data["children"] = children;
    return data;
}
