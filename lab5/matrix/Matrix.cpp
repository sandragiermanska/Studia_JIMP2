//
// Created by sandra on 07.04.18.
//

#include "Matrix.h"

using namespace std;
using namespace algebra;

algebra::Matrix::Matrix() {
    number_of_rows = 0;
    number_of_columns = 0;
    matrix_ = nullptr;
}

algebra::Matrix::Matrix(int rows, int columns){
    number_of_rows = rows;
    number_of_columns = columns;
    matrix_ = new complex<double>* [rows];
    if (rows > 0 && columns > 0) {
        for (int i = 0; i < rows; ++i) {
            matrix_[i] = new complex<double> [columns];
        }
    }
}

algebra::Matrix::Matrix(Matrix& other_matrix) {
    number_of_columns = other_matrix.number_of_columns;
    number_of_rows = other_matrix.number_of_rows;
    matrix_ = new complex<double>* [number_of_rows];
    for (int i = 0; i < number_of_rows; ++i) {
        matrix_[i] = new complex<double> [number_of_columns];
        for (int j = 0; j < number_of_columns; ++j) {
            matrix_[i][j] = other_matrix.matrix_[i][j];
        }
    }
}

algebra::Matrix::Matrix(std::initializer_list<std::vector<std::complex<double>>> list_init) {
    number_of_rows = list_init.size();
    number_of_columns = (*list_init.begin()).size();
    matrix_ = new complex<double>* [number_of_rows];
    int i = 0;
    auto ptr = list_init.begin();
    while (ptr != list_init.end()) {
        auto ptr2 = ptr->begin();
        int j = 0;
        matrix_[i] = new complex<double> [number_of_columns];

        while (ptr2 != ptr->end()) {
            matrix_[i][j] = *ptr2;
            ptr2++;
            j++;
        }
        ptr++;
        i++;
    }
}

algebra::Matrix::Matrix(const char* text) {
    int i = 0;
    if (text[2] == 0) {
        number_of_rows = 0;
        number_of_columns = 0;
        matrix_ = nullptr;
    }
    else {
        int row = 1, col = 1;
        while (text[i] != 0) {
            if (text[i] == ';') {
                row++;
            } else if (row == 1 && text[i] == ' ') {
                col++;
            }
            i++;
        }
        number_of_rows = row;
        number_of_columns = col;
        matrix_ = new complex<double>* [row];
        if (row > 0 && col > 0) {
            for (i = 0; i < row; ++i) {
                matrix_[i] = new complex<double> [col];
            }
        }
        bool is_real_part_of_number = true;
        i = 1;
        row = col = 0;
        complex<double> temp;
        while (text[i] != 0) {
            if (text[i] == ';') {
                row++;
                col = -1;
            } else if (text[i] == ' ') {
                col++;
                is_real_part_of_number = true;
            } else if (is_real_part_of_number) {
                matrix_[row][col] += atoi(&text[i]);
                is_real_part_of_number = false;
            } else if (text[i - 1] == 'i') {
                temp = complex<double> (0, atoi(&text[i]));
                matrix_[row][col] += temp;
            }
            i++;
        }
    }
}

algebra::Matrix::~Matrix() {
    if (matrix_){
        for (int i = 0; i < number_of_rows; ++i) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    }
}

void algebra::Matrix::Set(int row, int column, std::complex<double> value) {
    matrix_[row][column] = value;
}

complex<double> algebra::Matrix::Get(int row, int column) {
    return matrix_[row][column];
}

Matrix algebra::Matrix::Add(const Matrix& other_matrix) const {
    Matrix result(number_of_rows, number_of_columns);
    if (number_of_columns == other_matrix.number_of_columns && number_of_rows == other_matrix.number_of_rows) {
        for (int i = 0; i < number_of_rows; ++i) {
            for (int j = 0; j < number_of_columns; ++j) {
                result.Set(i, j, matrix_[i][j] + other_matrix.matrix_[i][j]);
            }
        }
    }
    return result;
}

Matrix algebra::Matrix::Sub(const Matrix other_matrix) { //odejmowanie
    Matrix result(number_of_rows, number_of_columns);
    if (number_of_columns == other_matrix.number_of_columns && number_of_rows == other_matrix.number_of_rows) {
        for (int i = 0; i < number_of_rows; ++i) {
            for (int j = 0; j < number_of_columns; ++j) {
                result.Set(i, j, matrix_[i][j] - other_matrix.matrix_[i][j]);
            }
        }
    }
    return result;
}

Matrix algebra::Matrix::Mul(Matrix& other_matrix) { //mnozenie
    int rows = 0, col = 0;
    if (number_of_columns == other_matrix.number_of_rows) {
        rows = number_of_rows;
        col = other_matrix.number_of_columns;
    }
    Matrix result(rows, col);
    for (int i = 0; i < result.number_of_rows; ++i) {
        for (int j = 0; j < result.number_of_columns; ++j) {
            complex<double> sum = 0;
            for (int k = 0; k < number_of_columns; ++k) {
                sum += matrix_[i][k] * other_matrix.matrix_[k][j];
            }
            result.Set(i, j, sum);
        }
    }
    return result;
}

Matrix algebra::Matrix::Mul(complex<double> number) {
    Matrix result(number_of_rows, number_of_columns);
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            result.Set(i, j, matrix_[i][j] * number);
        }
    }
    return result;
}

Matrix algebra::Matrix::Div(const Matrix other_matrix) { //dzielenie

}

Matrix algebra::Matrix::Div(complex<double> number) {
    Matrix result(number_of_rows, number_of_columns);
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            result.Set(i, j, matrix_[i][j] / number);
        }
    }
    return result;
}

Matrix algebra::Matrix::Pow(int number) {
    if (number_of_rows == number_of_columns) {
        if (number > 0) {
            Matrix result(*this);
            Matrix f(*this);
            for (int i = 1; i < number; ++i) {
                result = result.Mul(f);
            }
            return result;
        }
        else if (number == 0) {
            Matrix result(number_of_rows, number_of_columns);
            for (int i = 0; i < number_of_rows; ++i) {
                result.matrix_[i][i] = 1;
            }
            return result;
        }
    }
    else {
        Matrix res(0,0);
        return res;
    }
}

Matrix& algebra::Matrix::operator=(Matrix &&matrix) {
    if (this == &matrix) {
        return matrix;
    }
    for (int i = 0; i < number_of_rows; ++i) {
        delete [] matrix_[i];
    }
    delete [] matrix_;
    matrix_ = nullptr;
    swap(matrix_, matrix.matrix_);
}

string algebra::Matrix::Print() const {
    std::ostringstream strs;

    string result = "[";
    for (int i = 0; i < number_of_rows; ++i) {
        for (int j = 0; j < number_of_columns; ++j) {
            strs << (matrix_[i][j].real());
            result += strs.str();
            strs.str("");
            strs.clear();

            result += "i";
            strs << matrix_[i][j].imag();
            result += strs.str();
            strs.str("");
            strs.clear();
            if (j + 1 < number_of_columns) {
                result += ", ";
            }
        }
        if (i + 1 < number_of_rows) {
            result += "; ";
        }
    }
    result += "]";

    return result;
}

std::pair<size_t, size_t> Matrix::Size() {
    return pair<size_t, size_t>(number_of_rows, number_of_columns);
}