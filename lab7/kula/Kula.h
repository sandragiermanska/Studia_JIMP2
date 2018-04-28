//
// Created by giersand on 17.04.18.
//

#ifndef JIMP_EXERCISES_KULA_H
#define JIMP_EXERCISES_KULA_H

#include "Kolo.h"

class Kula: public Kolo{

public:
    Kula(int a, int b, int c, int d);
    double pole_pow();

    double z;
};


#endif //JIMP_EXERCISES_KULA_H
