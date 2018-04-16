//
// Created by sandra on 14.04.18.
//

#ifndef JIMP_EXERCISES_WORD_H
#define JIMP_EXERCISES_WORD_H

#include <string>

namespace datastructures {

    class Word {

    public:
        Word();
        Word(std::string text);
        ~Word();

        bool operator< (const Word other) const;
        bool operator== (const Word other) const;

        std::string Get() const;

    private:
        std::string word_;

    };
}

#endif //JIMP_EXERCISES_WORD_H
