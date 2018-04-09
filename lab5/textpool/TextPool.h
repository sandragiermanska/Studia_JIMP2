//
// Created by sandra on 06.04.18.
//

#ifndef JIMP_EXERCISES_TEXTPOOL_H
#define JIMP_EXERCISES_TEXTPOOL_H

#include <initializer_list>
#include <string>
#include <experimental/string_view>
#include <set>
#include <vector>

using namespace std::experimental;

namespace pool {

    class TextPool {

    public:
        TextPool();

//    //1. konstruktor kopiujący
//    XXX(const XXX &xxx);
        //2. konstruktor przenoszący
        TextPool(TextPool &&text);

        TextPool(std::initializer_list<std::string> list_init);
//    //3. operator przypisania kopiujący
//    XXX &operator=(const XXX &xxx);
        //4. operator przypisania przenoszący
        TextPool &operator=(TextPool &&text);

        //5. Destruktor
        ~TextPool();

        std::experimental::string_view Intern(const std::string &str);

        size_t StoredStringCount() const;

    private:
        std::vector<string_view> pool;

    };

}

#endif //JIMP_EXERCISES_TEXTPOOL_H
