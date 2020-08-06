//
// Created by user on 11/06/2020.
//

#include "Matrix.h"

/**
 * @def std::string DOUBLE_ASTRIX  "**"
 * @brief double astrix
 */
#define DOUBLE_ASTRIX "**"

/**
 * @def std::string DOUBLE_SPACES  "  "
 * @brief double spaces
 */
#define DOUBLE_SPACES "  "

/**
 * @def std::string ERROR_MSG  "Error: "
 * @brief The start of an error message
 */
#define ERROR_MSG "Error: "

/**
 * @def std::string BAD_INPUT  "bad input."
 * @brief The start of an error message
 */
#define BAD_INPUT "bad input."

/**
 * @def std::string INDEX_OUTSIDE_MATRIX  "the index is outside of matrix size."
 * @brief The index given is outside of the size of the matrix.
 */
#define INDEX_OUTSIDE_MATRIX "the index is outside of matrix size."

/**
 * @def std::string CANT_ADD  "cant add matrices of different sizes."
 * @brief The matrices have different sizes.
 */
#define CANT_ADD "cant add matrices of different sizes."

/**
 * @def std::string CANT_MULTIPLY  "cant multiply matrices with different col and row."
 * @brief The matrices have different row and column sizes.
 */
#define CANT_MULTIPLY "cant multiply matrices with different col and row."

/**
 * @def std::string NEGATIVE_NUMBERS  "cant create a matrix with negative numbers."
 * @brief cannot create a matrix with negative numbers.
 */
#define NEGATIVE_NUMBERS  "cant create a matrix with negative numbers."

/**
 * @def float LOW_PROB  0.1f
 * @brief The low probability bar
 */
#define LOW_PROB 0.1f

/**
 * @fn Matrix::Matrix(int rows, int cols)
 * @brief the constructor of the Matrix class.
 * @param rows the rows of the matrix.
 * @param cols the clos of the matrix.
 */
Matrix::Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        {
            std::cerr << ERROR_MSG << NEGATIVE_NUMBERS << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    _rows = rows;
    _cols = cols;
    _matrix = new float[rows * cols];
    _init();
}

/**
 * @fn Matrix::Matrix()
 * @brief the default constructor of the Matrix class initialises 1 row and 1 col.
 */
Matrix::Matrix() : Matrix(1, 1)
{
}

/**
 * @fn Matrix::Matrix(Matrix const &m)
 * @brief Constructs matrix from another Matrix m
 * @param m the matrix to copy from.
 */
Matrix::Matrix(Matrix const &m)
{
    _rows = m._rows;
    _cols = m._cols;
    _matrix = new float[_rows * _cols];
    for (int i = 0; i < (_rows * _cols); i++)
    {
        _matrix[i] = m._matrix[i];
    }
}

/**
 * @fn Matrix::~Matrix()
 * @brief the destructor of the matrix.
 */
Matrix::~Matrix()
{
    delete[] _matrix;
}

/**
 * @fn int Matrix::getRows() const
 * @brief gets the rows
 * @return returns the rows of the matrix.
 */
int Matrix::getRows() const
{
    return _rows;
}

/**
 * @fn int Matrix::getCols() const
 * @brief gets the cols
 * @return returns the cols of the matrix.
 */
int Matrix::getCols() const
{
    return _cols;
}

/**
 * @fn void Matrix::_init()
 * @brief initialises of the values in matrix to 0;
 */
void Matrix::_init()
{
    for (int i = 0; i < (_rows * _cols); i++)
    {
        _matrix[i] = 0;
    }
}

/**
 * @fn Matrix& Matrix::vectorize()
 * @brief turns the matrix to a vector.
 * @return returns the vectorized matrix.
 */
Matrix& Matrix::vectorize()
{
    Matrix transMatrix((_rows * _cols), 1);
    _rows = (_rows * _cols);
    _cols = 1;
    return *this;
}

/**
 * @fn void Matrix::plainPrint() const
 * @brief prints the values of the matrix.
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            std::cout << _matrix[(i * _cols) + j] << ' ';
        }
        std::cout << '\n';
    }
}

/**
 * @fn Matrix &Matrix::operator=(const Matrix &rhs)
 * @brief the assignments operator.
 * @param rhs the matrix to be assigned.
 * @return the current matrix after assignment.
 */
Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    if ((_rows * _cols) != (rhs.getCols() * rhs.getRows()))
    {
        delete[](_matrix);
        _matrix = new float[rhs._rows * rhs._cols];
    }
    _rows = rhs.getRows();
    _cols = rhs.getCols();
    for (int i = 0; i < (rhs.getRows() * rhs.getCols()); i++)
    {
        _matrix[i] = rhs._matrix[i];
    }
    return *this;
}

/**
 * @fn Matrix Matrix::operator*(const Matrix &rhs) const
 * @brief the multiply by matrix operator.
 * @param rhs the matrix to multiply.
 * @return a new matrix after multiplication.
 */
Matrix Matrix::operator*(const Matrix &rhs) const
{
    if (_cols != rhs.getRows())
    {
        {
            std::cerr << ERROR_MSG << CANT_MULTIPLY << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    Matrix newMatrix = Matrix(_rows, rhs.getCols());
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < rhs.getCols(); j++)
        {
            for (int k = 0; k < rhs.getRows(); k++)
            {
                newMatrix._matrix[(i * rhs.getCols()) + j] +=
                        _matrix[(i * _cols) + k] * rhs._matrix[(k * rhs.getCols()) + j];
            }
        }
    }
    return newMatrix;
}

/**
 * @fn Matrix Matrix::operator*(float rightC) const
 * @brief the multiply by scalar from right operator.
 * @param rightC the scalar.
 * @return a new matrix after multiplication.
 */
Matrix Matrix::operator*(float rightC) const
{
    Matrix newMatrix = Matrix(getRows(), getCols());
    for (int i = 0; i < (getRows() * getCols()); i++)
    {
        newMatrix._matrix[i] = _matrix[i] * rightC;
    }
    return newMatrix;
}

/**
 * @fn Matrix Matrix::operator+(const Matrix &rhs) const
 * @brief the addition matrix.
 * @param rhs the matrix to add.
 * @return a new matrix after addition.
 */
Matrix Matrix::operator+(const Matrix &rhs) const
{
    if (_rows != rhs.getRows() || _cols != rhs.getCols())
    {
        {
            std::cerr << ERROR_MSG << CANT_ADD << std::endl;
            exit(EXIT_FAILURE);
        }
    }
        Matrix newMatrix = Matrix(getRows(), getCols());
        for (int i = 0; i < (getCols() * getRows()); i++)
        {
            newMatrix._matrix[i] = _matrix[i] + rhs._matrix[i];
        }
        return newMatrix;
}

/**
 * @fn Matrix &Matrix::operator+=(const Matrix &rhs)
 * @brief the addition matrix and assignment.
 * @param rhs the matrix to add.
 * @return the current matrix after addition.
 */
Matrix &Matrix::operator+=(const Matrix &rhs)
{
    if (_rows != rhs.getRows() || _cols != rhs.getCols())
    {
        {
            std::cerr << ERROR_MSG << CANT_ADD << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < (getCols() * getRows()); i++)
    {
        _matrix[i] = _matrix[i] + rhs._matrix[i];
    }
    return *this;
}

/**
 * @fn float Matrix::operator()(int row, int col) const
 * @brief getting access to a certain value in matrix.
 * @param row the row index.
 * @param col the col index.
 * @return the value in the given index.
 */
float Matrix::operator()(int row, int col) const
{
    if (row < 0 || row >= _rows || col < 0 || col >= _cols)
    {
        std::cerr << ERROR_MSG << INDEX_OUTSIDE_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[(row * _cols) + col];
}

/**
 * @fn float Matrix::operator()(int row, int col) const
 * @brief getting access to a certain value in matrix with ability to change it..
 * @param row the row index.
 * @param col the col index.
 * @return the address of the value in the given index.
 */
float& Matrix::operator()(int row, int col)
{
    if (row < 0 || row >= _rows || col < 0 || col >= _cols)
    {
        std::cerr << ERROR_MSG << INDEX_OUTSIDE_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[(row * _cols) + col];
}

/**
 * @fn float Matrix::operator[](int i) const
 * @brief getting access to a certain value in matrix.
 * @param i the index.
 * @return the value in the given index.
 */
float Matrix::operator[](int i) const
{
    if (i < 0 || i >= (_rows * _cols))
    {
        std::cerr << ERROR_MSG << INDEX_OUTSIDE_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[i];
}

/**
 * @fn float& Matrix::operator[](int i)
 * @brief getting access to a certain value in matrix with ability to change it.
 * @param i the index.
 * @return the address of the value in the given index.
 */
float& Matrix::operator[](int i)
{
    if (i < 0 || i >= (_rows * _cols))
    {
        std::cerr << ERROR_MSG << INDEX_OUTSIDE_MATRIX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[i];
}

/**
 * @fn Matrix operator*(float leftC, const Matrix &matrix)
 * @brief the multiply by scalar from left operator.
 * @param leftC the scalar.
 * @param matrix the matrix to be multiplied.
 * @return a new matrix after multiplication.
 */
Matrix operator*(float leftC, const Matrix &matrix)
{
    Matrix newMatrix = Matrix(matrix.getRows(), matrix.getCols());
    for (int i = 0; i < (matrix.getRows() * matrix.getCols()); i++)
    {
        newMatrix._matrix[i] = leftC * matrix._matrix[i];
    }
    return newMatrix;
}

/**
 * @fn std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
 * @brief the output stream operator of the matrix.
 * @param os the output stream.
 * @param matrix the matrix.
 * @return an output stream with pretty export of matrix.
 */
std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < (matrix.getRows()); i++)
    {
        for (int j = 0; j < matrix.getCols(); j++)
        {
            if (matrix._matrix[(i * matrix.getCols()) + j] <= LOW_PROB)
            {
                os << DOUBLE_SPACES;
            }
            else
            {
                os << DOUBLE_ASTRIX;
            }
        }
        std::cout << "\n";
    }
    return os;
}

/**
 * @fn std::istream &operator>>(std::istream &is, const Matrix &matrix)
 * @brief the input stream operator of the matrix.
 * @param is the input stream.
 * @param matrix the matrix.
 * @return the input stream.
 */
std::istream &operator>>(std::istream &is, const Matrix &matrix)
{
    if (is.good())
    {
        is.read((char*) matrix._matrix, sizeof(float) * matrix._rows * matrix._cols);
        return is;
    }
    std::cerr << ERROR_MSG << BAD_INPUT << std::endl;
    exit(EXIT_FAILURE);
}




