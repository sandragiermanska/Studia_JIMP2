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

double geometry::Square::SideLengthPower(Point a, Point b) {
    return pow(a.GetX() - b.GetX(), 2) + pow(a.GetY() - b.GetY(), 2);
}

bool geometry::Square::IsSquare(){
    bool result = false;
    double diagonal_pow = SideLengthPower(a_, d_);
    double ab_pow = SideLengthPower(a_, b_);
    double ac_pow = SideLengthPower(a_, c_);
    double bd_pow = SideLengthPower(b_, d_);
    double cd_pow = SideLengthPower(c_, d_);
    if(diagonal_pow == ab_pow + ac_pow) {
        if(diagonal_pow == bd_pow + cd_pow){
            result = true;
        }
    }
    return result;
}

double geometry::Square::Circumference() {
    if (IsSquare()) {
        double result = 0;
        double temp = SideLengthPower(a_, b_);
        result += 4 * sqrt(temp);
        return result;
    }
    else {
        return 0;
    }
}

double geometry::Square::Area() {
    if(IsSquare()) {
        double temp = SideLengthPower(a_, b_);
        double side = sqrt(temp);
        return side * side;
    }
    else {
        return 0;
    }
}
