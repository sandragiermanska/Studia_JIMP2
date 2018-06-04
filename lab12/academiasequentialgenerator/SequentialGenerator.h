//
// Created by sandra on 03.06.18.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H

template<typename T, typename U>
class SequentialIdGenerator {
public:
    SequentialIdGenerator() {
        id_ = -1;
    }

    SequentialIdGenerator(U u) {
        id_ = u - 1;
    }

    int NextValue() {
        ++id_;
        return id_;
    }

private:
    int id_;
};


#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
