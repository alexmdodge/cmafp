#include "MediaFile.h"

#include <iostream>

#include "BinaryHelpers.h"

/* Constructors */

MediaFile::MediaFile(std::string name, int id, size_t size) {
    std::cout << "[CPP:MediaFile] CONSTRUCTING" << std::endl;

    _name = name;
    _size = size;
    _fill_pos = 0;
    _id = id;
    _is_closed = false;
    _is_invalid = false;

    _buffer = new uint8_t[_size];
}

MediaFile::MediaFile() {
    std::cout << "[CPP:MediaFile] CONSTRUCTING ERROR" << std::endl;

    _name = "ERROR";
    _size = 1;
    _fill_pos = 0;
    _id = 1;
    _is_closed = true;
    _is_invalid = true;
}

MediaFile::MediaFile(const MediaFile& file) {
    std::cout << "[CPP:MediaFile] COPYING" << std::endl;
    _name = file._name;
    _size = file._size;
    _fill_pos = file._fill_pos;
    _id = file._id;
    _is_closed = file._is_closed;
    _is_invalid = file._is_invalid;
    _buffer = file._buffer;
}

MediaFile::~MediaFile() {
    std::cout << "[CPP:MediaFile] DECONSTRUCTING" << std::endl;

    delete[] _buffer;
}

/* Members */

int MediaFile::id() {
    return _id;
}

size_t MediaFile::size() {
    return _size;
}

size_t MediaFile::buffer_index() {
    return _fill_pos;
}

std::string MediaFile::name() {
    return _name;
}

std::string MediaFile::status() {
    std::string result_rep;
    result_rep += "[ Name: " + name();
    result_rep += "-" + std::to_string(id());
    result_rep += " ][ BytesRead: " + std::to_string(buffer_index());
    result_rep += "/" + std::to_string(size());
    result_rep += " ]";

    return result_rep;
}

bool MediaFile::is_invalid() {
    return _is_invalid;
}

/* Byte Range Operations */

// TODO: Make these faster by not copying
uint8_t MediaFile::u8_from(size_t pos) {
    return _buffer[pos];
}

uint16_t MediaFile::u16_from(size_t pos) {
    return (uint16_t)(_buffer[pos] << 8) + _buffer[pos + 1];
}

uint32_t MediaFile::u32_from(size_t pos) {
    // clang-format off
    return (uint32_t)(_buffer[pos] << 24)
         + (uint32_t)(_buffer[pos + 1] << 16)
         + (uint32_t)(_buffer[pos + 2] << 8)
         + (uint32_t)(_buffer[pos + 3]);
    // clang-format on
}

uint64_t MediaFile::u64_from(size_t pos) {
    // clang-format off
    return ((uint64_t)(_buffer[pos]) << 56)
         + ((uint64_t)(_buffer[pos + 1]) << 48)
         + ((uint64_t)(_buffer[pos + 1]) << 40)
         + ((uint64_t)(_buffer[pos + 3]) << 32)
         + (uint64_t)(_buffer[pos + 4] << 24)
         + (uint64_t)(_buffer[pos + 5] << 16)
         + (uint64_t)(_buffer[pos + 6] << 8)
         + (uint64_t)(_buffer[pos + 7]);
    // clang-format on
}

/* File Management Operations */

void MediaFile::append(uint8_t val) {
    if (_is_closed || _is_invalid) {
        return;
    }

    if (_fill_pos > _size) {
        // Error with append operation, file buffer size is exceeded
        // Forcefully closing file preventing further operations
        _is_closed = true;
        return;
    }

    _buffer[_fill_pos] = val;
    _fill_pos++;
}

void MediaFile::close() {
    _is_closed = true;
}

void MediaFile::invalidate() {
    _is_invalid = true;
}
