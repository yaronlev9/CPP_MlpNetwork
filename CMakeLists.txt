cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex4 main.cpp MlpNetwork.cpp Dense.cpp Activation.cpp Matrix.cpp)