
#include "TrackBox.h"

#include "TrackHeaderBox.h"

TrackBox::TrackBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    TrackHeaderBox _tkhd{_file, _byte_offset};
    tkhd = _tkhd.to_json();
    _byte_offset = _tkhd.end_offset;

    children = {tkhd};
};

json TrackBox::to_json() {
    json data = Box::to_json();

    data["children"] = children;
    return data;
}
