//
// Created by zamol on 21.09.2025.
//
#include <vector>
#include<iostream>
#include<iomanip>

struct GaussianResult {
    std::vector<std::vector<double>> upTriangMat;
};

GaussianResult toUpperTriangular(const std::vector<std::vector<double>>& matrixA) {
    int rows = matrixA.size();
    int cols = matrixA[0].size();

    GaussianResult result { matrixA };
    auto& matrixTriang = result.upTriangMat;
    matrixTriang = matrixA;

    for(int j=0; j<std::min(rows,cols)-1; j++)
    {
        for(int i=j+1; i<rows; i++)
        {
            if (matrixTriang[j][j] == 0) throw std::runtime_error("Zero pivot encountered (need pivoting)");

            double temp=matrixTriang[i][j]/matrixTriang[j][j];

            for(int k=0; k<cols; k++) {
                matrixTriang[i][k]-=matrixTriang[j][k]*temp;
            }
        }
    }

    std::cout<<"\n ---------------------------------\n";
    std::cout<<"\n Upper Triangular Matrix is:\n";

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << std::setw(8) << std::setprecision(4) << matrixTriang[i][j];
        }
        std::cout << std::endl;
    }

    return result;
}