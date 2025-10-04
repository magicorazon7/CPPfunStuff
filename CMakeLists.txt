cmake_minimum_required(VERSION 4.0)
project(Gaussian)

set(CMAKE_CXX_STANDARD 20)

add_executable(Gaussian LUdecompose.cpp LUdecompose.h  main.cpp
        upTriangMat.cpp
        upTriangMat.h
        backWardSubstitution.cpp
        backWardSubstitution.h
        QRdecompose.cpp
        QRdecompose.h
        multiplyMatrices.cpp
        multiplyMatrices.h)
