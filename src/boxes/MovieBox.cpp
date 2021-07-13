
#include "MovieBox.h"

#include "MovieHeaderBox.h"
#include "TrackBox.h"

MovieBox::MovieBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    std::cout << "[MovieBox] start_offset: " << start_offset << std::endl;
    std::cout << "[MovieBox] Offset: " << _byte_offset << std::endl;
    std::cout << "[MovieBox] size: " << size << std::endl;

    MovieHeaderBox _mvhd{_file, _byte_offset};
    mvhd = _mvhd.to_json();
    _byte_offset = _mvhd.end_offset;

    std::cout << "[MovieBox] mvhd size: " << _mvhd.size << std::endl;
    std::cout << "[MovieBox] Offset: " << _byte_offset << std::endl;

    TrackBox _trak{_file, _byte_offset};
    trak = _trak.to_json();
    _byte_offset = _trak.end_offset;

    children = {mvhd, trak};
    end_offset = _byte_offset;
};

json MovieBox::to_json() {
    json data = Box::to_json();

    data["children"] = children;
    return data;
}
