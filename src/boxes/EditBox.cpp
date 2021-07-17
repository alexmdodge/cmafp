
#include "EditBox.h"

#include "EditListBox.h"

EditBox::EditBox(std::shared_ptr<MediaFile>& file, uint32_t start_offset) : Box{file, start_offset} {
    if (box_type != "edts") {
        return;
    }

    is_present = true;

    EditListBox _elst{_file, _byte_offset};
    elst = _elst.to_json();
    _byte_offset = _elst.end_offset;

    children = {elst};
};

json EditBox::to_json() {
    if (!is_present) {
        return {{"box_type", "edts"}, {"error", "Box not present"}};
    }

    json data = Box::to_json();

    data["children"] = children;

    return data;
}
