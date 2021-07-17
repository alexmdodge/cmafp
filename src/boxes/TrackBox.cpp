
#include "TrackBox.h"

#include "EditBox.h"
#include "MediaBox.h"
#include "TrackHeaderBox.h"

TrackBox::TrackBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    children = {};

    TrackHeaderBox _tkhd{_file, _byte_offset};
    tkhd = _tkhd.to_json();
    children.push_back(tkhd);
    _byte_offset = _tkhd.end_offset;

    EditBox _edts{_file, _byte_offset};

    if (_edts.is_present) {
        edts = _edts.to_json();
        children.push_back(edts);
        _byte_offset = _edts.end_offset;
    }

    MediaBox _mdia{_file, _byte_offset};
    mdia = _mdia.to_json();
    children.push_back(mdia);
    _byte_offset = _mdia.end_offset;

    end_offset = _byte_offset;
};

json TrackBox::to_json() {
    json data = Box::to_json();

    data["children"] = children;
    return data;
}
