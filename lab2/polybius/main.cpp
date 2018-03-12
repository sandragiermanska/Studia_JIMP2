//
// Created by sandra on 11.03.18.
//

#include "Polybius.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    if(argc == 4)
    {
        ifstream file_first(argv[1]);
        ofstream file_second(argv[2], ios_base::in | ios_base::app);
        char line[256];
        string text, result;
        if(!file_first) {
            cout << "Nie można otworzyć pierwszego pliku!" << endl;
        } else if(!file_second) {
            cout << "Nie można otworzyć drugiego pliku!" << endl;
        }
        while(!file_first.eof()){
            file_first.getline(line, 256);
            text = line;
            if(argv[3] == "0") {
                result = PolybiusDecrypt(text);
            } else if(argv[3] == "1"){
                result = PolybiusCrypt(text);
            }
            else
            {
                cout << "Błędny trzeci argument" << endl;
            }
            file_second << result;
        }
        file_first.close();
        file_second.close();
        return 0;
    }
}