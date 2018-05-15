//
// Created by giersand on 15.05.18.
//

#include "Algo.h"

using namespace std;

void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
    copy_n(v.begin(), n_elements, back_inserter(*out));
}

struct IsEqual
{
    const int d;
    IsEqual(int n) : d(n) {}
    bool operator()(int n) const { return n == d; }
};

bool algo::Contains(const std::vector<int> &v, int element) {
    return any_of(v.begin(), v.end(), IsEqual(element));
}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    transform(v->begin(), v->end(), v->begin(), [initial_value](int current) {return initial_value;});
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {
    vector<int> result(length);
    fill_n(result.begin(), length, initial_value);
    return result;
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    vector <string> result;
    transform(v.begin(), v.end(), back_inserter(result), [](double current) {return to_string(current);});
    return result;
}

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    set<string> result;
    transform(m.begin(), m.end(), inserter(result, result.begin()), [](pair<string, int> current) {return current.first;});
    return result;
}

bool algo::ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
    return any_of(v.begin(), v.end(), [key] (pair<string, int> current) {return current.first == key;});
}

std::vector<int> algo::Values(const std::map<std::string, int> &m) {
    vector<int> result;
    transform(m.begin(), m.end(), back_inserter(result), [](pair<string, int> current) {return current.second;});
    return result;
}

bool algo::ContainsValue(const std::map<std::string, int> &v, int value) {
    return any_of(v.begin(), v.end(), [value] (pair<string, int> current) {return current.second == value;});
}

//std::map<std::string, int> algo::DivisableBy(const std::map<std::string, int> &m, int divisor) {
//    map<string, int> result;
//    transform(m.begin(), m.end(), back_inserter(result), [divisor](pair<string, int> current) {if(current.second % divisor == 0) {
//        return current.second;}});
//    return  result;
//}
