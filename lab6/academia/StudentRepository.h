//
// Created by giersand on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "StudyYear.h"
#include <string>

namespace academia {

    class Student {

    private:
        std::string id;
        std::string first_name;
        std::string last_name;
        std::string program;
        StudyYear year;
    };
}

#endif //JIMP_EXERCISES_STUDENT_H
