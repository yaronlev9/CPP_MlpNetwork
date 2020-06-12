//
// Created by user on 11/06/2020.
//
#include <cmath>
#include "Activation.h"

Activation::Activation(ActivationType actType) {
    _actType = actType;
}

ActivationType Activation::getActivationType() {
    return _actType;
}

Matrix Activation::operator()(const Matrix &rhs) {
    Matrix newMatrix(rhs.getRows(), rhs.getCols());
    if (_actType == Relu)
    {
        for (int i = 0; i < (rhs.getCols()*rhs.getRows()); i++)
        {
            if (rhs._matrix[i] >= 0)
            {
                newMatrix[i] = rhs._matrix[i];
            }
        }
        return newMatrix;
    }
    else if (_actType == Softmax)
    {
        float sum = 0;
        Matrix exponentialMatrix(rhs.getRows(), rhs.getCols());
        for (int i = 0; i < (rhs.getCols()*rhs.getRows()); i++)
        {
            sum += std::exp(rhs._matrix[i]);
            exponentialMatrix[i] = std::exp(rhs._matrix[i]);
        }
        newMatrix = (float)(1/sum) * exponentialMatrix;
        return newMatrix;
    }

}

