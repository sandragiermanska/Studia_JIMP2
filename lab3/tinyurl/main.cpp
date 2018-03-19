//
// Created by sandra on 18.03.18.
//

#include "TinyUrl.h"

using namespace tinyurl;
int main(){
    unique_ptr <TinyUrlCodec> codec = tinyurl::Init();
    return 0;
}