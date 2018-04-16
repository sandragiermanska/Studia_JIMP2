//
// Created by sandra on 14.04.18.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include "Word.h"
#include "Counts.h"
#include <map>
#include <set>
#include <initializer_list>
#include <algorithm>
#include <iostream>

namespace datastructures {

    class WordCounter {

    public:
        WordCounter();
        WordCounter(std::initializer_list<Word> list_init);
        ~WordCounter();

        static WordCounter FromInputStream(std::istream& is);

        int operator[] (std::string text);
        friend std::ostream& operator<< (std::ostream &output, WordCounter& wc);

        int DistinctWords();
        int TotalWords();
        std::set<Word> Words();

    private:
        std::map<Word, Counts> dictionary;

    };
}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
