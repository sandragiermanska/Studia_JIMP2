//
// Created by giersand on 17.04.18.
//

#include "ArrayFill.h"

using namespace arrays;

void FillArray(int size, const ArrayFill &filler, std::vector<int> *v) {
    v->clear();
    v->reserve(size);
    for (int i = 0; i < size; i++) {
        v->emplace_back(filler.Value(i));
    }
}
