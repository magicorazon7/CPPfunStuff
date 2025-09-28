#include <cmath>
#include <vector>

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

    std::vector<std::vector<double>> firstRotation = std::vector<std::vector<double>>(size-1, std::vector<double>(size-1, 0.0));

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
        s = b/denominator;
    }

    for (int i = 0; i < rows-1; i++) {
        firstRotation[i][i] = c;
    }
    firstRotation[0][1] = -s;
    firstRotation[1][0] = s;

    return result;

}