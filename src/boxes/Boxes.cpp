
#include "Boxes.h"

#include "BinaryHelpers.h"

Boxes::Boxes(std::shared_ptr<MediaFile>& file) : _file(file), _byte_offset(0) {
    std::cout << "[Boxes] Offset: " << _byte_offset << std::endl;

    FileTypeBox _ftyp{_file, _byte_offset};
    _byte_offset = _ftyp.end_offset;

    std::cout << "[Boxes] ftyp size: " << _ftyp.size << std::endl;
    std::cout << "[Boxes] Offset: " << _byte_offset << std::endl;

    MovieBox _moov{_file, _byte_offset};
    _byte_offset = _moov.end_offset;

    std::cout << "[Boxes] moov size: " << _moov.size << std::endl;
    std::cout << "[Boxes] Offset: " << _byte_offset << std::endl;

    ftyp = _ftyp.to_json();
    moov = _moov.to_json();
}

Boxes::~Boxes() {}

std::string Boxes::to_json_str() {
    json reader{};

    reader = {ftyp, moov};
    return reader.dump();
}
