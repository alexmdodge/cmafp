
#include "MediaBox.h"

#include "MediaHeaderBox.h"

MediaBox::MediaBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    children = {};

    MediaHeaderBox _mdhd{_file, _byte_offset};
    mdhd = _mdhd.to_json();
    children.push_back(mdhd);
    _byte_offset = _mdhd.end_offset;

    end_offset = _byte_offset;
};

json MediaBox::to_json() {
    json data = Box::to_json();

    data["children"] = children;

    return data;
}
