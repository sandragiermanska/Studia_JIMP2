//
// Created by giersand on 17.04.18.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <vector>

namespace arrays {

    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(int size, const ArrayFill &filler, std::vector<int> *v);

    class IncrementalFill : public ArrayFill {
    public:
        IncrementalFill(int value);
        IncrementalFill(int first, int second);
        virtual int Value(int index) const override;
    private:
        int value_;
    };
}

#endif //JIMP_EXERCISES_ARRAYFILL_H
