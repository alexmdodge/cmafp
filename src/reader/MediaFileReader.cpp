#include "MediaFileReader.h"

#include <iostream>

#include "BinaryHelpers.h"

int media_file_index = -1;

std::vector<std::shared_ptr<MediaFile>> MediaFileReader::files{};

int MediaFileReader::create_file(std::string name, size_t size) {
    media_file_index++;
    const int file_id = media_file_index;
    std::shared_ptr<MediaFile> file = std::make_shared<MediaFile>(name, file_id, size);

    files.push_back(file);
    return file_id;
}

void MediaFileReader::append_to(int id, uint8_t value) {
    if (files.size() < id + 1) {
        std::cout << "[CPP]: Error loading file of ID: " << id << std::endl;
        return;
    }

    // std::cout << "[CPP]: Appending to file with id: " << id << std::endl;

    // Append buffer entry
    std::shared_ptr<MediaFile> file = files[id];
    file->append(value);

    // Log buffer entry comparison values
    // std::string hex_rep = BinaryHelpers::uint8_to_hex_string(value);
    // std::string bit_rep = BinaryHelpers::uint8_to_binary_string(value);
    // std::cout << "[CPP]: bufferVal" << file->buffer_index() << " hex: " << hex_rep << std::endl;
    // std::cout << "[CPP]: bufferVal" << file->buffer_index() << " bit: " << bit_rep << std::endl;
}

std::string MediaFileReader::close_file(int id) {
    if (files.size() < id + 1) {
        return "Error loading file of ID: " + std::to_string(id);
    }

    files[id]->close();
    return files[id]->status();
}

std::shared_ptr<MediaFile> MediaFileReader::get_file(int id) {
    if (files.size() < id + 1) {
        return std::shared_ptr<MediaFile>();
    }

    return files[id];
}
