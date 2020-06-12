//
// Created by user on 11/06/2020.
//

#include "Matrix.h"

Matrix::Matrix(int rows, int cols){
    _rows = rows;
    _cols = cols;
    _matrix = new float[rows*cols];
    init();
}

Matrix::Matrix(): Matrix(1, 1){}

Matrix::Matrix(Matrix const &m) {
    _rows = m._rows;
    _cols = m._cols;
    _matrix = new float[_rows*_cols];
    for (int i = 0; i < (_rows*_cols); i++)
    {
        _matrix[i] = m._matrix[i];
    }
}

Matrix::~Matrix() {
    delete[] _matrix;
}

int Matrix::getRows() const {
    return _rows;
}

int Matrix::getCols() const {
    return _cols;
}

void Matrix::init() {
    for (int i = 0; i < (_rows*_cols); i++)
    {
        _matrix[i] = 0;
    }
}

void Matrix::vectorize() {
    Matrix transMatrix((_rows*_cols), 1);
    for (int i = 0; i < (_rows*_cols); i++)
    {
        transMatrix._matrix[i] = _matrix[i];
    }
}

void Matrix::plainPrint() {
    for (int i = 0; i < (_rows*_cols); i++)
    {
        if (i % _rows == 0)
        {
            std::cout << '\n';
        }
        std::cout << _matrix[i] << ' ';
    }
}

Matrix& Matrix::operator= (const Matrix &rhs) {
    this->_rows = rhs.getRows();
    this->_cols = rhs.getCols();
    for (int i = 0; i < (rhs.getRows()*rhs.getCols()); i++)
    {
        this->_matrix[i] = rhs._matrix[i];
    }
    return *this;
}

Matrix &Matrix::operator*(const Matrix &rhs, float c) {
    return <#initializer#>;
}

Matrix &Matrix::operator*(float c, const Matrix &rhs) {
    return <#initializer#>;
}

Matrix &Matrix::operator+(const Matrix &lhs, const Matrix &rhs) {
    return <#initializer#>;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
    return <#initializer#>;
}

float Matrix::operator()(int row, int col) {
    return _matrix[(row*_rows) + col];
}

float Matrix::operator[](int i) {
    return _matrix[i];
}



