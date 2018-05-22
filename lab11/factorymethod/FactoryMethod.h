//
// Created by giersand on 22.05.18.
//

#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;
namespace factoryMethod {

    template <typename T>
    T Create () {
        T res{};
        return res;
    }

    template <typename T1, typename T2>
    T1 Add (T1 val1, T2 val2) {
        return val1 + (T1)val2;
    }

    template <typename T>
    auto Value (const T &ptr) {
        return *ptr;
    }

    template <typename T>
    T Mean (vector<T> vec) {
        T sum = Create();
        if (vec.begin() != vec.end()) {
            for (auto vec_val : vec) {
                sum += vec_val;
            }
            return sum / vec.size();
        }
        else {
            return 0;
        }
    }


    class MyType {
    public:
        string SayHello() {
            return "hello";
        }
    };

}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
