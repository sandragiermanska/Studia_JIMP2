//
// Created by giersand on 06.03.18.
//

#include "Array2D.h"
using namespace std;

int main()
{
    int n_rows, n_columns;
    cout << "Podaj ilosc wierszy\n";
    cin >> n_rows;
    cout << "Podaj ilosc kolumn\n";
    cin >> n_columns;
    int** array = Array2D(n_rows, n_columns);
    FullArray2D(array, n_rows, n_columns);
    PrintArray2D(array, n_rows, n_columns);
}