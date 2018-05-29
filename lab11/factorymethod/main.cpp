//
// Created by giersand on 22.05.18.
//

#include <iostream>
#include <memory>
#include "FactoryMethod.h"

using namespace std;
using namespace factoryMethod;

int main() {
    int a = 7;
    int b = 3;
    int add_int = Add(a,b);
    double c = 7.9876;
    double d = 3.1234;
    double add_double = Add(c,d);
    double add_int_and_double = Add(a,c);
    cout << add_int << "\t" << add_double << "\t" << add_int_and_double << endl;

    int* p_int = new int(33);
    int v_int = Value(p_int);
    vector<double> vec {7,8,9};
    double v_double_vector = Value(vec.begin());
    unique_ptr <string> str = make_unique <string> ("tekst");
    string v_str = Value(str);
    cout << v_int << "\t" << v_double_vector << "\t" << v_str << endl;

    vector<int> vec_int {1,2,3,4,5,6,7};
    int mean_vec_int = Mean(vec_int);
    vector<double> vec_double {1.5,4.5,3};
    vector<double> vec_empty;
    double mean_vec_double = Mean(vec_double);
    double mean_vec_empty = Mean(vec_empty);
    cout << mean_vec_int << "\t" << mean_vec_double << "\t" << mean_vec_empty << endl;
}