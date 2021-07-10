
#include "Boxes.h"

#include "BinaryHelpers.h"
#include "FileTypeBox.h"

Boxes::Boxes(std::shared_ptr<MediaFile>& file, json& reader) : _file(file), _byte_offset(0), _reader(reader) {}

Boxes::~Boxes() {}

void Boxes::ftyp() {
    FileTypeBox ftyp(_file, _byte_offset);

    _reader["FileTypeBox"] = {};
    _reader["FileTypeBox"]["size"] = ftyp.size;
    _reader["FileTypeBox"]["box_type"] = ftyp.box_type;
    _reader["FileTypeBox"]["major_brand"] = ftyp.major_brand;
    _reader["FileTypeBox"]["minor_version"] = ftyp.minor_version;
    _reader["FileTypeBox"]["compatible_brands"] = ftyp.compatible_brands;
}
