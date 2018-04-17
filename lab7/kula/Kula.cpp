//
// Created by giersand on 17.04.18.
//

#include "Kula.h"

Kula::Kula(int a, int b, int c, int d) {
    x = a;
    y = b;
    z = c;
    r = d;
}

double Kula::pole_pow() {
    return 4 * pole();
}