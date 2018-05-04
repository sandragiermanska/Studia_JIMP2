//
// Created by sandra on 29.04.18.
//

#include "MovieSubtitles.h"

using namespace std;
using namespace moviesubs;

void ReplaceAll(std::string &value, std::string &from, std::string &to) {
    size_t start_pos = 0;
    while((start_pos = value.find(from, start_pos)) != std::string::npos) {
        value.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void TransformStringVer0 (string* in, string* out, int move) {
    string line, line_cpy;
    int line_number = 0, control_sum = 0;
    vector<int> numbers_of_frames;

    std::smatch m;
    std::regex e{R"(\{(\w+)\})"};

    vector<string> array;
    auto it = array.begin();
    std::stringstream ss(*in);

    while (std::getline(ss, line, '\n')) {
        line_number++;
        line_cpy = line;
        //podzielenie tekstu na vector po {{.....}}
        while (std::regex_search(line, m, e)) {
            control_sum++;

            string temp = m[0].str();
            size_t pos = line.find(temp);

            it = array.insert(it, line.substr(0, pos));
            it = array.insert(it, line.substr(pos, temp.size()));

            line = line.substr(pos + temp.size());
        }
        if (!line.empty()) {
            it = array.insert(it, line.substr(0));
            line = "";
        }
        if (control_sum != 2) {
            throw InvalidSubtitleLineFormat();
        }
        //sklejanie wyniku z tablicy plus ewentualne zamiany
        for (auto it = array.rbegin(); it != array.rend(); ++it) {
            string value = *it;
            if (std::regex_search(value, m, e)) {
                string key = m[1].str();
                locale loc;
                if (!isdigit(key[0], loc) ) {
                    throw InvalidSubtitleLineFormat();
                }
                int num = stoi(key);
                numbers_of_frames.push_back(num);
                int size = numbers_of_frames.size();
                if (size % 2 == 0 && numbers_of_frames[size - 2] > numbers_of_frames[size - 1]) {
                    throw SubtitleEndBeforeStart(line_number, line_cpy);
                }
                num += move;
                string res = to_string(num);
                ReplaceAll(value, key, res);
                *out += value;
            } else {
                *out += *it;
            }
        }
        array.clear();
        *out += "\n";
        control_sum = 0;
    }
}

void AddTime(string *out, int ms, regex &regex_time_part, vector<string>* array, smatch &m, int line_number, string line) {
    int i = 0;
    int number = 0, number2;
    int array_size = array->size();
    for (int it = 0; it != array_size; ++it) {
        string value = (*array)[it];
        if (regex_search(value, m, regex_time_part)) {
            i++;
            string key = m[1].str();
            int num = stoi(key);
            switch (i) {
                case 4: {
                    number += num * 60 * 60 * 1000;
                    number2 = number;
                    number = 0;
                    break;
                }
                case 8: {
                    number += num * 60 * 60 * 1000;
                    break;
                }
                case 7:
                case 3: {
                    number += num * 60 * 1000;
                    break;
                }
                case 6:
                case 2: {
                    number += num * 1000;
                    break;
                }
                case 5:
                case 1: {
                    number += num;
                    break;
                }
            }
        }
    }
    number += ms;
    number2 += ms;
    if (number > number2) {
        throw SubtitleEndBeforeStart(line_number, line);
    }
    i = 0;
    for (auto it = array->rbegin(); it != array->rend(); ++it) {
        string value = *it;
        if (regex_search(value, m, regex_time_part)) {
            i++;
            int num;
            string key = m[1].str();
            switch (i) {
                case 1: {
                    num = number / (60 * 60 * 1000);
                    number -= num * (60 * 60 * 1000);
                    break;
                }
                case 2: {
                    num = number / (60 * 1000);
                    number -= num * (60 * 1000);
                    break;
                }
                case 3: {
                    num = number / 1000;
                    number -= num * 1000;
                    break;
                }
                case 4: {
                    num = number;
                    number = number2;
                    i = 0;
                    break;
                }
            }
            string res = to_string(num);
            if ((i > 0 && res.size() < 2) || (i == 0 && res.size() < 3)) {
                string temp = "0";
                temp += res;
                res = temp;
            }
            ReplaceAll(value, key, res);
            *out += value;
        } else {
            *out += *it;
        }
    }
}

void TransformStringVer1 (string* in, string* out, int ms) {
    string line, line_cpy;
    int line_number = 0, control_sum = 0;

    std::smatch m;
    std::regex regex_time_line{R"((\w+):(\w+):(\w+),(\w+) --> (\w+):(\w+):(\w+),(\w+))"};
    std::regex regex_time_part{R"((\d{2,3}))"};

    vector<string> array;
    auto it = array.begin();
    std::stringstream ss(*in);

    while (std::getline(ss, line, '\n')) {
        line_number++;
        line_cpy = line;
        //podzielenie tekstu na vector po {{.....}}
        if (std::regex_search(line, m, regex_time_line)) {
            if (line_number != 2 || !std::regex_search(line, m, regex_time_part)) {
                throw;
            }
            while (std::regex_search(line, m, regex_time_part)) {
                control_sum++;

                string temp = m[0].str();
                size_t pos = line.find(temp);

                it = array.insert(it, line.substr(0, pos));
                it = array.insert(it, line.substr(pos, temp.size()));

                line = line.substr(pos + temp.size());
            }

            if (!line.empty()) {
                it = array.insert(it, line.substr(0));
                line = "";
            }
            AddTime(out, ms, regex_time_part, &array, m, line_number, line_cpy);
        }
        else if (line_number == 2) {
            throw InvalidSubtitleLineFormat();
        }
        if (line_number != 2) {
            *out += line;
        }
        if (line_number == 4) {
            line_number = 0;
        }
        *out += "\n";
        array.clear();
    }
}

void Delay(string* in, string* out, int delay, int fps, int version_of_string) {

    if(delay < 0 || fps <= 0) {
        throw OutOfOrderFrames();
    }
    if (version_of_string == 0) {
        int move = delay * fps / 1000;
        TransformStringVer0(in, out, move);
    }
    else if (version_of_string == 1) {
        TransformStringVer1(in, out, delay);
    }
}

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int ms, int fps, stringstream *in, stringstream *out) {
    string str_in = in->str();
    string str_out;
    Delay(&str_in, &str_out, ms, fps, 0);
    out->str(str_out);
}

void SubRipSubtitles::ShiftAllSubtitlesBy(int ms, int fps, stringstream *in, stringstream *out) {
    string str_in = in->str();
    string str_out;
    Delay(&str_in, &str_out, ms, fps, 1);
    out->str(str_out);
}

int SubtitleEndBeforeStart::LineAt() const {
    return line_;
}

const char* SubtitleEndBeforeStart::what() const throw(){
    return error_.c_str();
}