//
// Created by zamol on 06.09.2025.
//
#include <stdexcept>
#include <vector>
#include<iostream>
#include<iomanip>

struct LUResult {
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;
};

double findSum(const std::vector<std::vector<double>>&,
    const std::vector<std::vector<double>>&,int rowL, int colU, int i);

LUResult LUdecompose(const std::vector<std::vector<double>>& matrixA) {

    int size = matrixA.size();

    int row = size;
    int col = size;

    LUResult result{
        std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0)),
        std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0))
    };


    auto& matrixL = result.L;
    auto& matrixU = result.U;

    for (int i = 0; i < row; i++) {
        matrixL[i][i] = 1; // заполняем диагональ единицами
        for (int j = i+1; j < col; j++) { //оставшиеся элементы в строке необходимо заполнить нулями!!!
            matrixL[i][j] = 0;
        }
    }

    for (int i = 0; i<col; i++) {

        for (int j = i; j<col; j++) {
            if (i == j) {

                double sum {};
                sum = findSum(matrixL,matrixU,i,i,i);
                matrixU[i][i] = matrixA[i][i] - sum;

                if (matrixU[i][i] == 0.0f) {
                    throw std::runtime_error("Zero pivot encountered, need pivoting");
                }

            } else {
                double sumL {};
                sumL = findSum(matrixL,matrixU,j,i,i);
                matrixL[j][i] = (matrixA[j][i] - sumL)/matrixU[i][i];

                double sumU {};

                sumU += findSum(matrixL,matrixU,i,j,i);

                matrixU[i][j] = matrixA[i][j] - sumU;
            }
        }

    }

    std::cout<<"\n ---------------------------------\n";
    std::cout<<"\n Matrix U is:\n";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(8) << std::setprecision(4) << matrixU[i][j];
        }
        std::cout << std::endl;
    }


    std::cout<<"\n ---------------------------------\n";
    std::cout<<"\n Matrix L is:\n";

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << std::setw(8) << std::setprecision(4) << matrixL[i][j];
        }
        std::cout << std::endl;
    }

    return result;
}

double findSum(const std::vector<std::vector<double>>& matrixL,
    const std::vector<std::vector<double>>& matrixU,int rowL, int colU,int iter) {
    double sum {};
    for (int p = 0; p<iter; p++) {
        sum += matrixL[rowL][p] * matrixU[p][colU];
    }

    return sum;
}

