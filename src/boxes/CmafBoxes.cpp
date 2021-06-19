
#include "CmafBoxes.h"

#include "BinaryHelpers.h"

// class CmafBoxes {
//   public:
//    static void with(shared_ptr<int> byte_offset, shared_ptr<int> bit_offset, shared_ptr<MediaFile> file);
//    static void ftype();

//   private:
//    static shared_ptr<int> _byte_offset;
//    static shared_ptr<int> _bit_offset;
//    static shared_ptr<MediaFile> _file;
//};

CmafBoxes::CmafBoxes() {}

CmafBoxes::~CmafBoxes() {
    // TODO: Do shared ptrs deallocate automatically when object
    // is deconstructed
    //_byte_offset = nullptr;
    //_bit_offset = nullptr;
    //_file = nullptr;
}

void CmafBoxes::from(std::shared_ptr<MediaFile> file) {
    byte_offset = 0;
    bit_offset = 0;
    file = file;
}

void CmafBoxes::ftype() {
    std::cout << "[CPP] Reading Box [ftype]" << std::endl;

    std::cout << "\tHeader: ";
    uint8_t header = file->u8_from(byte_offset);
    std::cout << header;
    byte_offset++;

    for (int i = 0; i < 64; i++) {
        header = file->u8_from(byte_offset);
        std::cout << header;
        std::cout << "_";
        byte_offset++;
    }

    std::cout << std::endl;
}
