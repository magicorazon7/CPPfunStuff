//
// Created by zamol on 04.10.2025.
//

#include <vector>

std::vector<std::vector<double>> multiply(
    const std::vector<std::vector<double>>& A,
    const std::vector<std::vector<double>>& B)
{
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    std::vector<std::vector<double>> C(n, std::vector<double>(m, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}