//
// Created by giersand on 27.03.18.
//

#ifndef JIMP_EXERCISES_XXX_H
#define JIMP_EXERCISES_XXX_H

#include <algorithm>

class XXX {
public:
    XXX();
    ~XXX();
    XXX(XXX &xxx);

    XXX & operator=(XXX &&xxx);
private:
    char *name_;
};


#endif //JIMP_EXERCISES_XXX_H
