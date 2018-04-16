//
// Created by sandra on 14.04.18.
//

#include "Word.h"

using namespace std;

datastructures::Word::Word() {

}

datastructures::Word::Word(std::string text) {
    word_ = text;
}

datastructures::Word::~Word() {

}

bool datastructures::Word::operator<(const Word other) const {
    if(word_ < other.word_) {
        return true;
    }
    else {
        return false;
    }
}

bool datastructures::Word::operator==(const Word other) const {
    if(word_ == other.word_) {
        return true;
    }
    else {
        return false;
    }
}

std::string datastructures::Word::Get() const {
    return word_;
}