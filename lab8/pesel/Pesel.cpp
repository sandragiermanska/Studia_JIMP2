//
// Created by giersand on 24.04.18.
//

#include "Pesel.h"

using namespace academia;
using namespace std;

Pesel::Pesel(const char* pesel) {
    validatePESEL(pesel);
    pesel_ = pesel;
    char* iter;
    while (iter != 0)
}

bool Pesel::validatePESEL(const char *pesel) {
    if(size_ != 11){
        throw InvalidPeselLength(pesel, 11);
    }
    //regex pesel_regex = R"(\d+)";
    for (int i = 0; i < size_; ++i) {
        if(pesel[i];
    }
//    InvalidPeselCharacter(pesel);
//    InvalidPeselChecksum(pesel, 11);
}

InvalidPeselChecksum::InvalidPeselChecksum(const char *pesel, int size):invalid_argument("") {

}

InvalidPeselLength::InvalidPeselLength(const char *pesel, int size):invalid_argument("")  {

}

InvalidPeselCharacter::InvalidPeselCharacter(const char *pesel):invalid_argument("")  {

}

AcademiaDataValidationError::AcademiaDataValidationError():invalid_argument("")  {

}