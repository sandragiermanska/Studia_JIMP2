//
// Created by giersand on 27.03.18.
//

#include "Xxx.h"

using namespace std;

XXX::XXX() : name_{new char[1024]} {

}

XXX::~XXX() {
    delete[] name_;
}

XXX::XXX(XXX &xxx) : name_{nullptr} {
    swap(name_, xxx.name_);
}

XXX & XXX::operator=(XXX &&xxx) {
    if (this == &xxx) {
        return xxx;
    }
    name_ = nullptr;
    swap(name_,xxx.name_);
}