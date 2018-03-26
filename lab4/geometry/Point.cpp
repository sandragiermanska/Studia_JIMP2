//
// Created by giersand on 20.03.18.
//

#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;

geometry::Point::Point():x_(0),y_(0){

}

geometry::Point::Point(double x, double y){
    x_ = x;
    y_ = y;
}

geometry::Point::~Point(){

}

double geometry::Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void geometry::Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double geometry::Point::GetX() const{
    return x_;
}

double geometry::Point::GetY() const{
    return y_;
}

void geometry::Point::SetX(double x){
    x_ = x;
}

void geometry::Point::SetY(double y){
    y_ = y;
}