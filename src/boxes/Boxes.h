#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "MediaFile.h"
#include "json.hpp"

using json = nlohmann::json;

// Box sizes are defined here in bytes, but referenced
// in the spec via bits
const uint32_t BOX_HEADER_BYTE_SIZE = 4;
const uint32_t BOX_HEADER_EXT_BYTE_SIZE = 8;

const uint32_t UINT_8_BYTE_SHIFT_SIZE = 1;
const uint32_t UINT_16_BYTE_SHIFT_SIZE = 2;
const uint32_t UINT_32_BYTE_SHIFT_SIZE = 4;
const uint32_t UINT_64_BYTE_SHIFT_SIZE = 8;

class Boxes {
   public:
    Boxes(std::shared_ptr<MediaFile>& file, json& reader);
    ~Boxes();

    uint64_t shift_u64();
    uint32_t shift_u32();
    std::string shift_u32_str();
    uint16_t shift_u16();
    uint8_t shift_u8();

    // clang-format off

    // - - - - - - - - - -
    // Header Boxes
    // - - - - - - - - - -

    // NL 0 Boxes
    void ftyp();    // Format Req: 1
    void moov();    // Format Req: 1

        // NL 1 Boxes
        void mvhd();    // Format Req: 1
        void trak();    // Format Req: 1

            // NL 2 Boxes
            void tkhd();    // Format Req: 1
            void edts();    // Format Req: CR

                // NL 3 Boxes
                void elst();    // Format Req: 1

            // NL 2 Boxes
            void mdia();    // Format Req: 1

                // NL 3 Boxes
                void mdhd();    // Format Req: 1
                void hdlr();    // Format Req: 1
                void elng();    // Format Req: 0/1
                void minf();    // Format Req: 1

                    // NL 4 Boxes
                    void vmhd();    // Format Req: CR
                    void smhd();    // Format Req: CR
                    void sthd();    // Format Req: CR
                    void dinf();    // Format Req: 1

                        // NL 5 Boxes
                        void dref();    // Format Req: 1

                    // NL 4 Boxes
                    void stbl();    // Format Req: 1

                        // NL 5 Boxes
                        void stsd();    // Format Req: 1
                        void stts();    // Format Req: 1
                        void stsc();    // Format Req: 1

                        void stsz();    // Format Req: 1
                        void stsz2();

                        void stco();    // Format Req: 1
                        void sgpd();    // Format Req: CR
                        void stss();    // Format Req: CR
            // NL 2 Boxes
            void udta();    // Format Req: 0/1

                // NL 3 Boxes
                void cprt();    // Format Req: *
                void kind();    // Format Req: *

        // NL 1 Boxes
        void mvex();    // Format Req: 1

            // NL 2 Boxes
            void mehd();    // Format Req: 0/1
            void trex();    // Format Req: 1

        // NL 1 Boxes
        void pssh();    // Format Req: *

    // clang-format on

   private:
    json& _reader;
    uint32_t _byte_offset;
    std::shared_ptr<MediaFile>& _file;
};
