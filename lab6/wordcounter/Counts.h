//
// Created by sandra on 14.04.18.
//

#ifndef JIMP_EXERCISES_COUNTS_H
#define JIMP_EXERCISES_COUNTS_H

namespace datastructures {

    class Counts {

    public:
        Counts();
        Counts(int number);
        ~Counts();

        bool operator< (const Counts other) const;
        bool operator> (const Counts other) const;
        bool operator== (const Counts other) const;
        Counts& operator++ ();

        int Get();

//        operator int() const;

    private:
        int number_;

    };
}

#endif //JIMP_EXERCISES_COUNTS_H
