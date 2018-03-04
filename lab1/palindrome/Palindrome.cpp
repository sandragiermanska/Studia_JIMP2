//
// Created by sandra on 04.03.18.
//

#include "Palindrome.h"
using namespace std;

bool is_palindrome(string str)
{
    int length = str.length();
    int number_of_check = length / 2;
    bool result = true;
    int i = 0;
    while(result && i < number_of_check)
    {
        if(str[i] != str[length - 1 - i])
        {
            result = false;
        }
        i++;
    }
    return result;
}