//
// Created by Davide on 15-Apr-19.
//

#ifndef FILE_H
#define FILE_H

#include "Base.h"
#include <cstdlib>
#include <vector>
#include <memory>

class File : public Base {

private:
    std::weak_ptr <Base> parent;
    uintmax_t size;

public:
    uintmax_t getSize() const;

    void ls(int indent = 0) const override;

    int mType() const override;

    File(std::string, uintmax_t);
};


#endif //FILE_H
