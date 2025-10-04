//
// Created by zamol on 28.09.2025.
//

#ifndef GAUSSIAN_ROTATIONMATRICES_H
#define GAUSSIAN_ROTATIONMATRICES_H

#include <vector>

struct QRresult {
    std::vector<std::vector<double>> Qacc;
    std::vector<std::vector<double>> R;
};

QRresult QRdecompose(const std::vector<std::vector<double>>&);

#endif //GAUSSIAN_ROTATIONMATRICES_H