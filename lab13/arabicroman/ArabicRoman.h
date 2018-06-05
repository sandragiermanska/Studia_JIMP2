//
// Created by giersand on 05.06.18.
//

#ifndef JIMP_EXERCISES_ARABICROMAN_H
#define JIMP_EXERCISES_ARABICROMAN_H

#include <string>
#include <map>
#include <stdexcept>

using namespace std;

string ArabicToString(int arabic) {
    if (arabic <= 0) {
        throw invalid_argument{""};
    }
    string result;
    int number = arabic;
    map<int,string> letters_one;
    map<int,string> letters_five;
    letters_one[1] = "I";
    letters_five[5] = "V";
    letters_one[10] = "X";
    letters_five[50] = "L";
    letters_one[100] = "C";
    letters_five[500] = "D";
    letters_one[1000] = "M";

    for(auto current = letters_one.crbegin(); current != letters_one.crend(); ++current) {
        if (number >= 5*current->first) {
            if (number == 9*current->first) {
                result.append(current->second);
                result.append(letters_one[10*current->first]);
                number -= 9*current->first;
            } else {
                result.append(letters_five[5*current->first]);
                number %= 5*current->first;

            }
        }
        if (number >= current->first) {
            if (number == 4*current->first) {
                result.append(current->second);
                result.append(letters_five[5*current->first]);
            } else {
                int number_of_iter = number / current->first;
                for (int i = 0; i < number_of_iter; ++i) {
                    result.append(current->second);
                    number -= current->first;
                }
            }
        }
    }
    return result;
}


#endif //JIMP_EXERCISES_ARABICROMAN_H
