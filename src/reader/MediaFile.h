#pragma once

#include <string>

class MediaFile {
   public:
    int id();
    size_t size();
    size_t buffer_index();
    uint8_t u8_from(size_t pos);
    uint16_t u16_from(size_t pos);
    uint32_t u32_from(size_t pos);
    uint64_t u64_from(size_t pos);
    std::string name();
    std::string status();
    bool is_invalid();

    MediaFile(std::string name, int id, size_t size);
    MediaFile();
    MediaFile(const MediaFile& file);
    ~MediaFile();

    void append(uint8_t val);
    void close();
    void invalidate();

   private:
    int _id;
    bool _is_closed;
    bool _is_invalid;
    size_t _size;
    size_t _fill_pos;
    std::string _name;

    uint8_t* _buffer;
};
