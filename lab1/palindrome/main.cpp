//
// Created by sandra on 04.03.18.
//

#include <iostream>
#include "Palindrome.h"
using namespace std;

int main() {
    int option;
    do {
        cout << "Wybierz opcje:" << endl <<
             "1.Sprawdz palindrom" << endl <<
             "2.Wyjscie" << endl;
        cin >> option;
    } while(option != 1 && option != 2);
    if(option == 1)
    {
        string value;
        cin >> value;
        bool palindrome = is_palindrome(value);
        if(palindrome)
        {
            cout << "To jest palindrom";
        }
        else
        {
            cout << "To nie jest palindrom";
        }
    }
}
