//
// Created by sandra on 14.04.18.
//

#include "WordCounter.h"

using namespace datastructures;
using namespace std;

int main() {
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a")};
    cout << counter;
}