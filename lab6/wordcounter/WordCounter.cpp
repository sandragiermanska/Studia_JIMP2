//
// Created by sandra on 14.04.18.
//

#include "WordCounter.h"

using namespace std;
using namespace datastructures;

datastructures::WordCounter::WordCounter() {

}

datastructures::WordCounter::WordCounter(initializer_list<Word> list_init) {
    auto ptr = list_init.begin();
    while (ptr != list_init.end()) {
        if (&dictionary[*ptr]) {
            dictionary[*ptr].operator++();
        }
        else {
            pair<Word, Counts> new_word (*ptr, 1);
            dictionary.insert(new_word);
        }
        ptr++;
    }
}

datastructures::WordCounter::~WordCounter() {

}

WordCounter datastructures::WordCounter::FromInputStream(istream &is) {
    string text, word;
    is >> text;
    int size = text.size();
    WordCounter wc;
    for (int i = 0; i < size; ++i) {
        if(text[i] > 64 && text[i] < 91 || text[i] > 60 && text[i] < 123) {
            word += text[i];
        }
        else if(word.size() > 0) {
            Word word_result(word);
            if(wc.dictionary.count(word_result) > 0) {
                wc.dictionary[word_result].operator++();
            }
            else {
                pair<Word, Counts> element (word_result, 1);
                wc.dictionary.insert(element);
            }
            string word;
        }
    }
}

int datastructures::WordCounter::operator[](string text) {
    Word word(text);
    if(dictionary.count(word) > 0) {
        return dictionary[word].Get();
    }
    else {
        return 0;
    }
}

ostream& datastructures::operator<< (std::ostream &output, WordCounter& wc) {
    for (map<Word, Counts>::iterator it = wc.dictionary.begin(); it != wc.dictionary.end(); ++it) {
        output << (*it).first.Get() << "\t" << (*it).second.Get() << endl;
    }
    return output;
}

int datastructures::WordCounter::DistinctWords() {
    return dictionary.size();
}

int datastructures::WordCounter::TotalWords() {
    int sum = 0;
    for (map<Word, Counts>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        sum += (*it).second.Get();
    }
    return sum;
}

std::set<Word> datastructures::WordCounter::Words() {
    std::set<Word> words;
    for (map<Word, Counts>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
        words.insert((*it).first);
    }
    return words;
}