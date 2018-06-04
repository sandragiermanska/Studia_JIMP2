//
// Created by sandra on 03.06.18.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H

#include <chrono>
#include <utility>
#include <string>

using namespace std;
namespace profiling {

    template<typename T>
    pair<T, double> TimeRecorder(T(*f)()) {
        auto start = chrono::steady_clock::now();
        T temp = f();
        auto end = chrono::steady_clock::now();
        double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000000.;
        return pair<T, double>(temp, time);
    }

    template<typename F>
    auto TimeRecorder(F f) -> pair<decltype(f()), double> {
        using T = decltype(f());
        auto start = chrono::steady_clock::now();
        auto temp = f();
        auto end = chrono::steady_clock::now();
        double time = chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1000000.;
        return pair<T, double>(temp, time);
    }

}

#endif //JIMP_EXERCISES_TIMERECORDER_H
