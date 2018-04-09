//
// Created by sandra on 07.04.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <complex>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <cmath>

namespace algebra {
    class Matrix {

    public:
        Matrix();
        Matrix(int rows, int columns);
        Matrix(Matrix& other_matrix);
        Matrix(std::initializer_list<std::vector<std::complex<double>>> list_init);
        Matrix(const char *text);
        ~Matrix();

        void Set(int row, int column, std::complex<double> value);
        std::complex<double> Get(int row, int column);

        Matrix Add(const Matrix& other_matrix) const;
        Matrix Sub(const Matrix other_matrix); //odejmowanie
        Matrix Mul(Matrix& other_matrix); //mnozenie
        Matrix Mul(std::complex<double> number);
        Matrix Div(const Matrix other_matrix); //dzielenie
        Matrix Div(std::complex<double> number);
        Matrix Pow(int number);

        std::string Print() const;
        std::pair<size_t, size_t> Size();

        Matrix& operator=(Matrix &&matrix);

    private:
        int number_of_rows;
        int number_of_columns;
        std::complex<double>** matrix_;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
