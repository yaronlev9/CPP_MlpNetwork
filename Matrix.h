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

/**
 * @class Matrix the class of the Matrix
 * @brief The class object of the matrix.
 */
class Matrix
{
    /**
     * @fn Matrix operator*(float leftC, const Matrix &matrix)
     * @brief the multiply by scalar from left operator.
     * @param leftC the scalar.
     * @param matrix the matrix to be multiplied.
     * @return a new matrix after multiplication.
     */
    friend Matrix operator*(float leftC, const Matrix &matrix);

    /**
     * @fn std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
     * @brief the output stream operator of the matrix.
     * @param os the output stream.
     * @param matrix the matrix.
     * @return an output stream with pretty export of matrix.
     */
    friend std::ostream & operator<<(std::ostream &os, const Matrix &matrix);

    /**
     * @fn std::istream &operator>>(std::istream &is, const Matrix &matrix)
     * @brief the input stream operator of the matrix.
     * @param is the input stream.
     * @param matrix the matrix.
     * @return the input stream.
     */
    friend std::istream & operator>>(std::istream &is, const Matrix &matrix);

private:

    /**
    * @var _rows the rows of the matrix.
    * @brief the the rows of the matrix.
    */
    int _rows;

    /**
    * @var _cols the cols of the matrix.
    * @brief the the cols of the matrix.
    */
    int _cols;

    /**
    * @var _matrix an array of the values of the matrix.
    * @brief an array of the values of the matrix.
    */
    float* _matrix;

    /**
     * @fn void Matrix::_init()
     * @brief initialises of the values in matrix to 0;
     */
    void _init();

public:

    /**
     * @fn Matrix::Matrix()
     * @brief the default constructor of the Matrix class initialises 1 row and 1 col.
     */
    Matrix();

    /**
     * @fn Matrix::Matrix(int rows, int cols)
     * @brief the constructor of the Matrix class.
     * @param rows the rows of the matrix.
     * @param cols the clos of the matrix.
     */
    Matrix(int rows, int cols);

    /**
     * @fn Matrix::Matrix(Matrix const &m)
     * @brief Constructs matrix from another Matrix m
     * @param m the matrix to copy from.
     */
    Matrix(Matrix const &m);

    /**
     * @fn Matrix::~Matrix()
     * @brief the destructor of the matrix.
     */
    ~Matrix();

    /**
     * @fn int Matrix::getRows() const
     * @brief gets the rows
     * @return returns the rows of the matrix.
     */
    int getRows() const;

    /**
     * @fn int Matrix::getCols() const
     * @brief gets the cols
     * @return returns the cols of the matrix.
     */
    int getCols() const;

    /**
     * @fn Matrix& Matrix::vectorize()
     * @brief turns the matrix to a vector.
     * @return returns the vectorized matrix.
     */
    Matrix& vectorize();

    /**
     * @fn void Matrix::plainPrint() const
     * @brief prints the values of the matrix.
     */
    void plainPrint() const;

    /**
     * @fn Matrix &Matrix::operator=(const Matrix &rhs)
     * @brief the assignments operator.
     * @param rhs the matrix to be assigned.
     * @return the current matrix after assignment.
     */
    Matrix& operator=(const Matrix& rhs);

    /**
     * @fn Matrix Matrix::operator*(const Matrix &rhs) const
     * @brief the multiply by matrix operator.
     * @param rhs the matrix to multiply.
     * @return a new matrix after multiplication.
     */
    Matrix operator*(const Matrix& rhs) const;

    /**
     * @fn Matrix Matrix::operator*(float rightC) const
     * @brief the multiply by scalar from right operator.
     * @param rightC the scalar.
     * @return a new matrix after multiplication.
     */
    Matrix operator*(float rightC) const;

    /**
     * @fn Matrix Matrix::operator+(const Matrix &rhs) const
     * @brief the addition matrix.
     * @param rhs the matrix to add.
     * @return a new matrix after addition.
     */
    Matrix operator+(const Matrix& rhs) const;

    /**
     * @fn Matrix &Matrix::operator+=(const Matrix &rhs)
     * @brief the addition matrix and assignment.
     * @param rhs the matrix to add.
     * @return the current matrix after addition.
     */
    Matrix& operator+=(const Matrix& rhs);

    /**
     * @fn float Matrix::operator()(int row, int col) const
     * @brief getting access to a certain value in matrix.
     * @param row the row index.
     * @param col the col index.
     * @return the value in the given index.
     */
    float operator()(int row, int col) const;

    /**
     * @fn float Matrix::operator()(int row, int col) const
     * @brief getting access to a certain value in matrix with ability to change it..
     * @param row the row index.
     * @param col the col index.
     * @return the address of the value in the given index.
     */
    float& operator()(int row, int col);
    /**
     * @fn float Matrix::operator[](int i) const
     * @brief getting access to a certain value in matrix.
     * @param i the index.
     * @return the value in the given index.
     */
    float operator[](int i) const;

    /**
     * @fn float& Matrix::operator[](int i)
     * @brief getting access to a certain value in matrix with ability to change it.
     * @param i the index.
     * @return the address of the value in the given index.
     */
    float& operator[](int i);
};
#endif //MATRIX_H
