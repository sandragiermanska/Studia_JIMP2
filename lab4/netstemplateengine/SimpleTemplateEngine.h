//
// Created by sandra on 25.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>
#include <regex>

namespace nets {
    class View {

    public:
        View(std::string pattern);
        std::string Render(const std::unordered_map<std::string, std::string> &model) const;

    private:
        std::string _pattern;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
