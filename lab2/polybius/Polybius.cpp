//
// Created by sandra on 11.03.18.
//

#include "Polybius.h"
using namespace std;

char Lowercase(char character)
{
    if(character <= 'Z' && character >= 'A')
        character -= ('Z'-'z');
    return character;
}

string PolybiusCrypt(string message)
{
    string result;
    map<char, int> polybius_square = {{'a', 11}, {'b', 12}, {'c', 13}, {'d', 14}, {'e', 15},
                                      {'f', 21}, {'g', 22}, {'h', 23}, {'i', 24}, {'j', 24}, {'k', 25},
                                      {'l', 31}, {'m', 32}, {'n', 33}, {'o', 34}, {'p', 35},
                                      {'q', 41}, {'r', 42}, {'s', 43}, {'t', 44}, {'u', 45},
                                      {'v', 51}, {'w', 52}, {'x', 53}, {'y', 54}, {'z', 55}};
    int length = message.length();
    for (int i = 0; i < length; ++i) {
        message[i] = Lowercase(message[i]);
        if(polybius_square[message[i]] != 0){
            result += to_string(polybius_square[message[i]]);
        }
    }
    return result;
}

string PolybiusDecrypt(string crypted)
{
    string result;
    map<int, char> polybius_square = {{11, 'a'}, {12, 'b'}, {13, 'c'}, {14, 'd'}, {15, 'e'},
                                      {21, 'f'}, {22, 'g'}, {23, 'h'}, {24, 'i'}, {25, 'k'},
                                      {31, 'l'}, {32, 'm'}, {33, 'n'}, {34, 'o'}, {35, 'p'},
                                      {41, 'q'}, {42, 'r'}, {43, 's'}, {44, 't'}, {45, 'u'},
                                      {51, 'v'}, {52, 'w'}, {53, 'x'}, {54, 'y'}, {55, 'z'}};
    int length = crypted.length();
    int size = 8;
    int tab_size = (size - 1 + length)/size;
    string tab[tab_size];
    for (int j = 0; j < tab_size; ++j) {
        tab[j] = crypted.substr(j * size, size);
        int i_crypted = stoi(tab[j]);
        int temp;
        length = tab[j].length();
        for (int i = 0; i < length; i += 2) {
            temp = i_crypted / pow(10, length - i - 2);
            i_crypted -= temp * pow(10, length - i - 2);
            result += polybius_square[temp];
        }
    }
    return result;
}