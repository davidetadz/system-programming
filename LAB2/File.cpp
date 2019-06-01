//
// Created by Davide on 15-Apr-19.
//

#include "File.h"

uintmax_t File::getSize() const {
    return size;
}

void File::ls(int indent) const {
    for (int i = 0; i < indent; i++)
        printf("\t\t");
    printf("%s %ju\n", this->getName().c_str(), this->getSize());
}

File::File(std::string name, uintmax_t size) : Base(name), size(size) {}

int File::mType() const {
    return 2;
}
