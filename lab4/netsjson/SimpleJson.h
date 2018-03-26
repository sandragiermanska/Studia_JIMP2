//
// Created by sandra on 25.03.18.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <vector>
#include <map>

namespace nets {

    class JsonValue {
    public:
        JsonValue(double value);
        JsonValue(int value);
        JsonValue(bool value);
        JsonValue(std::string value);
        JsonValue(std::vector<JsonValue> js);
        JsonValue(std::map<std::string, JsonValue> obj_v);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;

    private:
        std::string res;
        std::map<std::string, JsonValue> obj_v;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
