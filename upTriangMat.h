//
// Created by zamol on 21.09.2025.
//

#ifndef GAUSSIAN_UPTRIANGMAT_H
#define GAUSSIAN_UPTRIANGMAT_H

#include <vector>
struct GaussianResult {
    std::vector<std::vector<double>> upTriangMat;
};

GaussianResult toUpperTriangular(const std::vector<std::vector<double>>&);
#endif //GAUSSIAN_UPTRIANGMAT_H