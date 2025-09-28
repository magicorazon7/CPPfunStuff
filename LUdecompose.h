//
// Created by zamol on 13.09.2025.
//

#ifndef GAUSSIAN_LUDECOMPOSE_H
#define GAUSSIAN_LUDECOMPOSE_H

#include <vector>

struct LUResult {
    std::vector<std::vector<double>> L;
    std::vector<std::vector<double>> U;
};

LUResult LUdecompose(const std::vector<std::vector<double>>&);
#endif //GAUSSIAN_LUDECOMPOSE_H