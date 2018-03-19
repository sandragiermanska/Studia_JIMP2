//
// Created by sandra on 18.03.18.
//

#include "TinyUrl.h"

using namespace tinyurl;

std::unique_ptr<TinyUrlCodec> tinyurl::Init() {
    //map<array<char, 6>, string> data;
    unique_ptr<TinyUrlCodec> result (new TinyUrlCodec);
    //result.get()->data = data;
    return result;
}

void ::tinyurl::NextHash(std::array<char, 6> *state) {
    int i = 5;
    bool change_next = true;
    while(change_next && i > -1) {
        if (state->at(i) == 57) {
            state->at(i) = 65;
            change_next = false;
        }
        else if(state->at(i) == 90){
            state->at(i) = 97;
            change_next = false;
        }
        else if(state->at(i) == 122){
            state->at(i--) = 48;
        }
        else {
            state->at(i)++;
            change_next = false;
        }
    }
}

std::string tinyurl::Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec){
    array<char, 6> hash;
    string result;
    if (codec->get()->data.empty()){
        hash = {'0', '0', '0', '0', '0', '0'};
    }
    else {
        hash = codec->get()->data.end()->first;
        NextHash(&hash);
    }
    codec->get()->data.insert(pair<array<char, 6>, string>(hash, url));
    for (int i = 0; i < 6; ++i) {
        result[i] = hash[i];
    }
    return result;
}

std::string tinyurl::Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash){
    array<char, 6> hash_tab;
    for (int i = 0; i < 6; ++i) {
        hash_tab[i] = hash[i];
    }
    string result = codec.get()->data[hash_tab];
    return result;
}