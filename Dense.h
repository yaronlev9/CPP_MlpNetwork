//
// Created by user on 11/06/2020.
//

#ifndef EX4_DENSE_H
#define EX4_DENSE_H
#include "Matrix.h"
#include "Activation.h"

class Dense
{
private:
    Matrix _w;
    Matrix _bias;
    ActivationType _actType;

public:
    Dense(const Matrix& w, const Matrix& bias, ActivationType actType);
    Matrix getWeights() const;
    Matrix getBias() const;
    ActivationType getActivation() const;
    Matrix operator()(const Matrix &m);
};
#endif //EX4_DENSE_H
