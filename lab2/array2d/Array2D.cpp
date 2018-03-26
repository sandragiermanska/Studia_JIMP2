//
// Created by giersand on 06.03.18.
//

#include "Array2D.h"
using namespace std;

int **Array2D(int n_rows, int n_columns)
{
    if(n_rows <= 0 || n_columns <= 0)
    {
        return nullptr;
    }
    int** array = new int* [n_rows];
    for (int i = 0; i < n_rows; ++i) {
        array[i] = new int[n_columns];
    }
    FullArray2D(array, n_rows, n_columns);
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns)
{
    if(array) {
        for (int i = 0; i < n_rows; ++i) {
            delete [] array[i];
        }
    }
}

void FullArray2D(int **array, int n_rows, int n_columns)
{
    if(array)
    {
        int number = 1;
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_columns; ++j) {
                array[i][j] = number;
                number++;
            }
        }
    }
}

void PrintArray2D(int **array, int n_rows, int n_columns) {
    if (array) {
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_columns; ++j) {
                cout << array[i][j] << '\t';
            }
            cout << endl;
        }
    }
}