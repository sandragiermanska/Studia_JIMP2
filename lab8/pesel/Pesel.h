//
// Created by giersand on 24.04.18.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <stdexcept>
#include <regex>

using namespace std;

namespace academia {

    class Pesel {
    public:
        Pesel(const char* pesel);

        bool validatePESEL(const char *pesel);

    private:
        string pesel_;
        int size_;
    };

    class InvalidPeselChecksum:public invalid_argument{
    public:
        InvalidPeselChecksum(const char* pesel, int size);
    };
    class InvalidPeselLength:public invalid_argument{
    public:
        InvalidPeselLength(const char* pesel, int size);
    };
    class InvalidPeselCharacter:public invalid_argument{
    public:
        InvalidPeselCharacter(const char* pesel);
    };
    class AcademiaDataValidationError:public invalid_argument{
    public:
        AcademiaDataValidationError();
    };
}

#endif //JIMP_EXERCISES_PESEL_H
