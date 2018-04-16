//
// Created by sandra on 14.04.18.
//

#include "Counts.h"

using namespace datastructures;

datastructures::Counts::Counts() {
    number_ = 0;
}

datastructures::Counts::Counts(int number) {
    number_ = number;
}

datastructures::Counts::~Counts() {

}

bool datastructures::Counts::operator< (const Counts other) const {
    if (number_ < other.number_) {
        return true;
    }
    else {
        return false;
    }
}

bool datastructures::Counts::operator> (const Counts other) const {
    if (number_ > other.number_) {
        return true;
    }
    else {
        return false;
    }
}

bool datastructures::Counts::operator== (const Counts other) const {
    if (number_ == other.number_) {
        return true;
    }
    else {
        return false;
    }
}

Counts& datastructures::Counts::operator++ () {
    number_++;
    return *this;
}

int datastructures::Counts::Get() {
    return number_;
}

//datastructures::Counts::operator int() const {
//    return number_;
//}