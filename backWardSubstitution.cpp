
#include <vector>
#include<iostream>
#include<iomanip>

std::vector<double> doBackwardSub(const std::vector<std::vector<double>>& matrixAB) {
    int cols = matrixAB[0].size();
    int n = cols - 1; // number of unknowns

    std::vector<double> x(n);

    for (int i = n - 1; i >= 0; --i) {
        double s = 0.0;
        for (int j = i + 1; j < n; ++j) {
            s += matrixAB[i][j] * x[j];
        }
        x[i] = (matrixAB[i][n] - s) / matrixAB[i][i];
    }

    std::cout<<"\n The Solution is:\n";
    for(int i=0; i<n; i++)
        std::cout<<"x["<<std::setw(3)<<i+1<<"]="<<std::setw(7)<<std::setprecision(4)<<x[i]<<std::endl;

    return x;

}