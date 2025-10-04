
#include <cmath>
#include <vector>
#include "multiplyMatrices.h"

struct QRresult {
    std::vector<std::vector<double>> Qacc;
    std::vector<std::vector<double>> R;
};

QRresult QRdecompose(const std::vector<std::vector<double>>& matrixA) {
    int size = matrixA.size();
    int rows = size;
    int cols = size;

    QRresult result{
        std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0)),
        std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0))
    };

    result.R = matrixA;

    std::vector<std::vector<double>> firstRotation = std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0));
    std::vector<std::vector<double>> secondRotation = std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0));
    std::vector<std::vector<double>> thirdRotation = std::vector<std::vector<double>>(size, std::vector<double>(size, 0.0));

    int p,q,k;
    p = 0;
    k = 0;
    q = 1;
    double a = matrixA[p][k]; // pivot (on or above diagonal)
    double b = matrixA[q][k]; // value to eliminate (below diagonal)

    double c{0};
    double s{0};
    double denominator = std::hypot(a,b);

    if (b == 0) {
        c = 1;
        s = 0;
    } else {
        c = a/denominator;
        s = -b/denominator;
    }

    for (int i = 0; i < rows-1; i++) {
        firstRotation[i][i] = c;
    }
    firstRotation[0][1] = -s;
    firstRotation[1][0] = s;
    firstRotation[2][2] = 1;

    result.R = multiply(firstRotation,result.R);

    k = 0;
    p = 0;
    q = 2;
    a = result.R[p][k];
    b = result.R[q][k];

    c = 0;
    s = 0;
    denominator = std::hypot(a,b);

    if (b == 0) {
        c = 1;
        s = 0;
    } else {
        c = a/denominator;
        s = -b/denominator;
    }

    secondRotation[1][1] = 1;

    secondRotation[0][0] = c;
    secondRotation[2][2] = c;
    secondRotation[0][2] = -s;
    secondRotation[2][0] = s;

    result.R = multiply(secondRotation,result.R);
    result.Qacc = multiply(firstRotation,secondRotation);

    k = 1;
    p = 1;
    q = 2;
    a = result.R[p][k];
    b = result.R[q][k];

    c = 0;
    s = 0;
    denominator = std::hypot(a,b);

    if (b == 0) {
        c = 1;
        s = 0;
    } else {
        c = a/denominator;
        s = -b/denominator;
    }

    thirdRotation[0][0] = 1;
    thirdRotation[1][1] = c;
    thirdRotation[2][2] = c;
    thirdRotation[1][2] = -s;
    thirdRotation[2][1] = s;

    result.R = multiply(thirdRotation,result.R);
    result.Qacc = multiply(thirdRotation,result.Qacc);

    return result;

}