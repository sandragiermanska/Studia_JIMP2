//
// Created by giersand on 17.04.18.
//

#include "Kula.h"
#include "Kolo.h"
#include <iostream>

using namespace std;

int main(){
    Kula k(0,0,0,10);
    double pole = k.pole();
    cout << pole;
}