//
// Created by sandra on 06.04.18.
//

#include "TextPool.h"

pool::TextPool::TextPool(){

}

pool::TextPool::TextPool(TextPool &&text){
    //pool = nullptr;
    swap(pool, text.pool);
}

pool::TextPool::TextPool(std::initializer_list<std::string> list_init){
    auto ptr = list_init.begin();
    while (ptr != list_init.end()) {
        bool exist = false;
        for (std::vector<string_view >::iterator it = pool.begin() ; it != pool.end(); ++it) {
            if (*it == *ptr) {
                exist = true;
                break;
            }
        }
        if(!exist){
            pool.push_back(*ptr);
        }
        ptr++;
    }
}

pool::TextPool & pool::TextPool::operator=(TextPool &&text){
    if (this == &text) {
        return text;
    }
    //pool = nullptr;
    swap(pool, text.pool);
}

pool::TextPool::~TextPool(){

}

std::experimental::string_view pool::TextPool::Intern(const std::string &str) {
    const string_view result;
    for (std::vector<string_view >::iterator it = pool.begin() ; it != pool.end(); ++it) {
        if (*it == str) {
            return *it;
        }
    }
    pool.push_back(str);
    return pool.back();
}

size_t pool::TextPool::StoredStringCount() const {
    return pool.size();
}
