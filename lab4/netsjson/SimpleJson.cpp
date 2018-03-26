//
// Created by sandra on 25.03.18.
//

#include "SimpleJson.h"
#include <iomanip>
#include <sstream>

using ::std::experimental::make_optional;

void replace_all(std::string& value, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = value.find(from, start_pos)) != std::string::npos) {
        value.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

nets::JsonValue::JsonValue(double value){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    res = stream.str();
}

nets::JsonValue::JsonValue(int value){
    res = std::to_string(value);
}

nets::JsonValue::JsonValue(bool value){
    if (value) {
        res = "true";
    }
    else {
        res = "false";
    }
}

nets::JsonValue::JsonValue(std::string value){
    std::string s_v = value;
    replace_all(s_v, "\\", "\\\\");
    replace_all(s_v, "\"", "\\\"");

    res = "\"" + s_v + "\"";
}
nets::JsonValue::JsonValue(std::vector<nets::JsonValue> js){
    res = "[";
    for (int i = 0; i < js.size(); ++i) {
        res += js[i].ToString();
        if(i< js.size() - 1){
            res += ", ";
        }
    }
    res += "]";
}
nets::JsonValue::JsonValue(std::map<std::string, nets::JsonValue> obj_v){
    this->obj_v = obj_v;
    res = "{";
    for (std::map<std::string, nets::JsonValue>::iterator it=obj_v.begin(); it!=obj_v.end(); ++it) {
        std::string key = it->first;
        replace_all(key, "\\", "\\\\");
        replace_all(key, "\"", "\\\"");

        res += "\"" + key + "\": " + it->second.ToString() + ", ";
    }
    res.pop_back();
    res.pop_back();
    res += "}";
}

std::experimental::optional<nets::JsonValue> nets::JsonValue::ValueByName(const std::string &name) const {

    return make_optional(obj_v.at(name));
}

std::string nets::JsonValue::ToString() const {
    return res;
}

