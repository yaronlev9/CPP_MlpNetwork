// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

// Insert Matrix class here...
class Matrix
{
private:
    int _rows;
    int _cols;

    void init();

public:
    Matrix(int rows, int cols);
    Matrix();
    Matrix(Matrix const &m);
    ~Matrix();
    int getRows() const;
    int getCols() const;
    void vectorize();
    void plainPrint();
    Matrix& operator=(const Matrix& rhs);
    Matrix& operator*(const Matrix& lhs, float c);
    Matrix& operator*(float c, const Matrix& rhs);
    Matrix& operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    float operator()(int row, int col);
    float operator[](int i);

    float* _matrix;
};
#endif //MATRIX_H
