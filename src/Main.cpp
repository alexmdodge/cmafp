
#include <execinfo.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

#include "BinaryHelpers.h"
#include "CmafParser.h"
#include "MediaFileReader.h"

void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

void log(std::string msg) {
    std::cout << msg << std::endl;
}

std::string parse_cmaf_header(int id) {
    std::shared_ptr<MediaFile> header_file = MediaFileReader::get_file(id);

    if (header_file->is_invalid()) {
        std::cout << "[CPP] Error parsing header file, invalid file reference" << std::endl;
        return "{ \"error\": \"Error parsing header\"}";
    }

    return CmafParser::parse_header(header_file);
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV, handler);  // install our handler
    std::cout << "Num args: " << argc << std::endl;
    std::cout << argv[1] << std::endl;

    FILE *file;
    char *buffer;
    size_t file_length;

    file = fopen(argv[1], "rb");  // Open the file in binary mode
    fseek(file, 0, SEEK_END);     // Jump to the end of the file
    file_length = ftell(file);    // Get the current byte offset in the file
    rewind(file);                 // Jump back to the beginning of the file

    buffer = new char[file_length];       // Enough memory for the file
    fread(buffer, file_length, 1, file);  // Read in the entire file
    fclose(file);                         // Close the file

    std::cout << "Length is: " << file_length << std::endl;

    int file_id = MediaFileReader::create_file("init", file_length);

    for (auto i = 0; i < file_length; i++) {
        uint8_t val = (uint8_t)buffer[i];

        if ((file_length - i) < 50) {
            std::cout << "Index: " << i << " -- ";
            std::cout << "Writing: " << BinaryHelpers::uint8_to_hex_string(val) << std::endl;
        }
        MediaFileReader::append_to(file_id, val);
    }

    std::string result = MediaFileReader::close_file(file_id);
    std::cout << "File Created: " << result << std::endl;

    std::string data = parse_cmaf_header(file_id);

    std::cout << data << std::endl;
    delete buffer;
    return 0;
}
