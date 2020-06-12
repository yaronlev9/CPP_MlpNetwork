//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H
#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

// Insert Activation class here...
class Activation
{
private:
    ActivationType _actType;

public:
    Activation(ActivationType actType);
    ActivationType getActivationType();
    Matrix operator()(const Matrix& rhs);
};
#endif //ACTIVATION_H
