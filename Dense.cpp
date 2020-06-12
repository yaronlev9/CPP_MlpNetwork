//
// Created by user on 11/06/2020.
//

#include "Dense.h"
#include "Matrix.h"
#include "Activation.h"

Dense::Dense(const Matrix& w, const Matrix& bias, ActivationType actType) {
    _w = w;
    _bias = bias;
    _actType = actType;
}

Matrix Dense::getWeights() const {
    return _w;
}

ActivationType Dense::getActivation() const {
    return _actType;
}

Matrix Dense::getBias() const {
    return _bias;
}

Matrix Dense::operator()(const Matrix &m) {
    Activation act(_actType);
    return act((getWeights() * m) + getBias());
}

