//
// Created by sandra on 07.04.18.
//

#include <iostream>
#include "Matrix.h"

using namespace std;
using namespace algebra;

int main(int argc, char* argv[]){
    Matrix m("[1i3 2i588 3; 3907 4 5; 6 7 87]");
    Matrix ma("[]");
    cout << "Macierz pierwsza: " << m.Print() << endl;
    cout << "Macierz druga: " << ma.Print() << endl;

    Matrix m1{{1.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}}; //argv[1]);
    Matrix m2{{3.0i, 0., 0.}, {0., 1.0i, 0.}, {0., 0., 1.0i}};

    cout << "Macierz pierwsza: " << m1.Print() << endl;
    cout << "Macierz druga: " << m2.Print() << endl;

    cout << "Dodawanie" << (m1.Add(m2)).Print() << endl;
    cout << "Odejmowanie" << (m1.Sub(m2)).Print() << endl;
    cout << "Mnożenie" << (m1.Mul(m2)).Print() << endl;
    cout << "Potęgowanie" << (m1.Pow(2)).Print() << endl;
    cout << "Potęgowanie" << (m2.Pow(2)).Print() << endl;
}