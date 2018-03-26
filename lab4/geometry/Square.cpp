//
// Created by giersand on 20.03.18.
//

#include "Square.h"

using namespace std;

geometry::Square::Square():a_(0, 0), b_(0, 0), c_(0, 0), d_(0, 0) {

}

geometry::Square::Square(Point a, Point b, Point c, Point d) {
    a_ = a;
    b_ = b;
    c_ = c;
    d_ = d;
}

geometry::Square::~Square() {

}

double geometry::Square::Circumference() {
    double result = 0;
    double temp = pow(a_.GetX() - b_.GetX(), 2) + pow(a_.GetY() - b_.GetY(), 2);
    result += 2*sqrt(temp);
    temp = pow(c_.GetX() - b_.GetX(), 2) + pow(c_.GetY() - b_.GetY(), 2);
    result += 2*sqrt(temp);
    return result;
}

double geometry::Square::Area() {
    double temp = pow(a_.GetX() - b_.GetX(), 2) + pow(a_.GetY() - b_.GetY(), 2);
    double one_side = sqrt(temp);
    temp = pow(c_.GetX() - b_.GetX(), 2) + pow(c_.GetY() - b_.GetY(), 2);
    double two_side = sqrt(temp);
    double result = one_side * two_side;
    return result;
}
