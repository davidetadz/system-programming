//
// Created by Davide on 15-Apr-19.
//

#include "Base.h"

std::string Base::getName() const {
    return this->name;
}

Base::Base(std::string name): name(name){}
