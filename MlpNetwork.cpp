//
// Created by user on 11/06/2020.
//

#include "MlpNetwork.h"
#include "Activation.h"

/**
 * @fn MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases)
 * @brief the constructor of the MLPNetwork class.
 * @param weights the array of the weights.
 * @param biases the array of the biases.
 */
MlpNetwork::MlpNetwork(const Matrix *weights, const Matrix *biases):_layers
{
    Dense(weights[0], biases[0], Relu),
    Dense(weights[1], biases[1], Relu),
    Dense(weights[2], biases[2], Relu),
    Dense(weights[3], biases[3], Softmax)
}
{
}

/**
 * @fn Digit MlpNetwork::operator()(const Matrix &m) const
 * @brief Applies the entire network on input.
 * @param m the matrix of the image.
 * @return returns the digit.
 */
Digit MlpNetwork::operator()(const Matrix &m) const
{
    Digit number;
    Matrix finalVector = _layers[3](_layers[2](_layers[1](_layers[0](m))));
    float max_val = 0;
    int digit = 0;
    for (int i = 0; i < (finalVector.getRows() * finalVector.getCols()); i++)
    {
        if (finalVector[i] > max_val)
        {
            max_val = finalVector[i];
            digit = i;
        }
    }
    number.probability = max_val;
    number.value = digit;
    return number;
}
