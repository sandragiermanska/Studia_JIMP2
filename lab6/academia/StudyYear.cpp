//
// Created by giersand on 10.04.18.
//

#include "StudyYear.h"

using namespace academia;

academia::StudyYear::StudyYear() {
    study_year_ = 1;
}

academia::StudyYear::StudyYear(int year) {
    study_year_ = year;
}

StudyYear& academia::StudyYear::operator++() {
    ++study_year_;
    return *this;
}

StudyYear& academia::StudyYear::operator--() {
    --study_year_;
    return *this;
}

bool academia::StudyYear::operator< (const StudyYear other) const {
    if (this->study_year_ < other.study_year_) {
        return true;
    }
    else {
        return false;
    }
}

academia::StudyYear::operator int() const {
    return study_year_;
}
