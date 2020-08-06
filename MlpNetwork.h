//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Dense.h"
#include "Digit.h"

/**
 * @def int MLP_SIZE 4
 * @brief the number of layers.
 */
#define MLP_SIZE 4

/**
 * @var MatrixDims ingDims
 * @brief the dimensions of the image.
 */
const MatrixDims imgDims = {28, 28};

/**
 * @var MatrixDims weightsDims[]
 * @brief the the dimensions of the weights.
 */
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};

/**
 * @var MatrixDims biasDims[]
 * @brief the the dimensions of the biases.
 */
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

// Insert MlpNetwork class here...

/**
 * @class MlpNetwork the class of the network.
 * @brief The class object of the mlp network.
 */
class MlpNetwork
{
private:

    /**
    * @var _layers the array of the layers.
    * @brief the array of the layers.
    */
    Dense _layers[MLP_SIZE];

public:

    /**
     * @fn MlpNetwork(const Matrix weights[], const Matrix biases[])
     * @brief the constructor of the MLPNetwork class.
     * @param weights the array of the weights.
     * @param biases the array of the biases.
     */
    MlpNetwork(const Matrix weights[], const Matrix biases[]);

    /**
     * @fn Digit operator()(const Matrix &m) const
     * @brief Applies the entire network on input.
     * @param m the matrix of the image.
     * @return returns the digit.
     */
    Digit operator()(const Matrix &m) const;
};
#endif // MLPNETWORK_H
