//
// Created by sandra on 11.03.18.
//

#include "XorCypherBreaker.h"

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary)
{
    const int letters = 26;
    const char start = 97;
    int length_cryptogram = cryptogram.size();
    int number_of_words = dictionary.size();
    long int number_of_keys = pow(letters, key_length);
    map<int,int> hits;
    char key[key_length];
    for (int i = 0; i < number_of_keys; ++i) {
        for (int j = 0; j < key_length; ++j) {
            key[j] = ((int)(i / pow(letters, j)) % letters) + start;
        }
        string text;
        for (int k = 0; k < length_cryptogram; ++k) {
            text += cryptogram[k] ^ key[k % key_length];
        }
        int hit = 0;
        for (int l = 0; l < number_of_words; ++l) {
            int found = -1;
            do {
                string test = " " + dictionary[l] + " ";
                found = text.find(test, found + 1);
                hit ++;
            } while(found != string::npos);
        }
        if(hit > number_of_words) {
            hits.insert(pair<int, int>(i, hit));
        }
    }
    int key_with_max_hits = hits.begin()->first;

    for (std::map<int,int>::iterator it=hits.begin(); it!=hits.end(); ++it) {
        if (hits[key_with_max_hits] < it->second){
            key_with_max_hits = it->first;
        }
    }

    string result;
    for (int j = 0; j < key_length; ++j) {
        result += ((int)(key_with_max_hits / pow(letters, j)) % letters) + start;
    }
    return result;

}