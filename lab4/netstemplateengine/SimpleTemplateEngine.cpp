//
// Created by sandra on 25.03.18.
//

#include "SimpleTemplateEngine.h"
using namespace std;

void replace_all(std::string& value, std::string& from, std::string& to) {
    size_t start_pos = 0;
    while((start_pos = value.find(from, start_pos)) != std::string::npos) {
        value.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

nets::View::View(std::string pattern) {
    _pattern = pattern;
}

std::string nets::View::Render(const std::unordered_map<std::string, std::string> &model) const {
    std::string result = _pattern;

    std::smatch m;
    std::regex e {R"(\{\{(\w+)\}\})"};

    vector<string> array;
    std::vector<string>::iterator it = array.begin();

    //podzielenie tekstu na vector po {{.....}}
    while (std::regex_search(result, m, e)) {

        string temp = m[0].str();
        size_t pos = result.find(temp);

        it = array.insert(it, result.substr(0, pos));
        it = array.insert(it, result.substr(pos, temp.size()));

        result = result.substr(pos + temp.size());
    }
    if (result != "") {
        it = array.insert(it, result.substr(0));
        result = "";
    }
    //sklejanie wyniku z tablicy plus ewentualne zamiany
    for(std::vector<string>::reverse_iterator it = array.rbegin(); it != array.rend(); ++it) {
        string value = *it;
        if (std::regex_search(value, m, e)) {
            string key = m[1].str();
            string to = "";

            if (model.find(key) != model.end()) {
                to = model.at(key);
            }
            string from = m[0].str();

            replace_all(value, from, to);
            
            result += value;
        }
        else {
            result += *it;
        }
    }

    return result;
}