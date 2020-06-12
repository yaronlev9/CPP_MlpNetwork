//
// Created by user on 11/06/2020.
//

#include "MlpNetwork.h"
#include "Activation.h"

MlpNetwork::MlpNetwork(Matrix weights[], Matrix biases[]) {
    _layers = (Dense*)malloc(sizeof(Dense)*4);
    _weights = weights;
    _biases = biases;
    for (int i = 0; i < 3; i++)
    {
        _layers[i] = Dense(weights[i], biases[i], Relu);
    }
    _layers[3] = Dense(weights[3], biases[3], Softmax);
}

Digit MlpNetwork::operator()(const Matrix &m) {
    Digit number;
    Matrix finalVector = _layers[3](_layers[2](_layers[1](_layers[0](m))));
    float max_val = 0;
    int digit = 0;
    for (int i = 0; i < (finalVector.getRows()*finalVector.getCols()); i++)
    {
        if (finalVector[i] > max_val)
        {
            max_val = finalVector[i];
            digit = i;
        }
    }
    number.probability = max_val;
    number.value = digit;
    free(_layers);
    return number;
}
