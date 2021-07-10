
#include "MovieBox.h"

MovieBox::MovieBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Atom{file, start_offset} {
    children = {};
};
