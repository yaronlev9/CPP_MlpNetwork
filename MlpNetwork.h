//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Dense.h"
#include "Digit.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

// Insert MlpNetwork class here...
class MlpNetwork
{
private:

    Matrix* _weights;
    Matrix* _biases;
    Dense* _layers;

public:
    MlpNetwork(Matrix weights[], Matrix biases[]);
    Digit operator()(const Matrix &m);
};
#endif // MLPNETWORK_H
