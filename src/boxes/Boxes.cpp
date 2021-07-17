
#include "Boxes.h"

#include "BinaryHelpers.h"

Boxes::Boxes(std::shared_ptr<MediaFile>& file) : _file(file), _byte_offset(0) {
    FileTypeBox _ftyp{_file, _byte_offset};
    ftyp = _ftyp.to_json();
    _byte_offset = _ftyp.end_offset;

    MovieBox _moov{_file, _byte_offset};
    moov = _moov.to_json();
    _byte_offset = _moov.end_offset;
}

Boxes::~Boxes() {}

std::string Boxes::to_json_str() {
    json reader{};

    reader = {ftyp, moov};
    return reader.dump();
}
