//
// Created by sandra on 04.03.18.
//

#include "DoubleBasePalindromes.h"
using namespace std;

uint64_t DoubleBasePalindromes(int max_vaule_exculsive)
{
    uint64_t sum = 0;
    int tab_dec[20], tab_bin[64];
    int temp, length, power, number_of_check, j;
    bool is_palindrome_dec, is_palindrome_bin;

    for (int i = 0; i < max_vaule_exculsive; ++i)
    {
        temp = i;
        length = 0;
        while(temp != 0)
        {
            length++;
            tab_dec[length - 1] = temp % 10;
            temp /= 10;
        }
        is_palindrome_dec = true;
        number_of_check = length / 2;
        j = 0;

        while(is_palindrome_dec && j < number_of_check)
        {
            if(tab_dec[j] != tab_dec[length - 1 - j])
            {
                is_palindrome_dec = false;
            }
            j++;
        }
        if (is_palindrome_dec)
        {
            temp = i;
            length = 0;
            while (temp != 0)
            {
                length++;
                tab_bin[length - 1] = temp % 2;
                //temp -= tab_bin[length - 1];
                temp /= 2;
            }
            is_palindrome_bin = true;
            number_of_check = length / 2;
            j = 0;
            while(is_palindrome_bin && j < number_of_check)
            {
                if(tab_bin[j] != tab_bin[length - 1 - j])
                {
                    is_palindrome_bin = false;
                }
                j++;
            }
            if (is_palindrome_bin)
            {
                sum += i;
            }
        }
    }
    return sum;
}