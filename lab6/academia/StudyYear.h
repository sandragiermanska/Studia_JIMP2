//
// Created by giersand on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDYYEAR_H
#define JIMP_EXERCISES_STUDYYEAR_H

namespace  academia {

    class StudyYear {
    public:
        StudyYear();
        StudyYear(int year);

        StudyYear &operator++();
        StudyYear &operator--();

        bool operator< (const StudyYear other) const;
        operator int() const;

    private:
        int study_year_;
    };
}

#endif //JIMP_EXERCISES_STUDYYEAR_H
