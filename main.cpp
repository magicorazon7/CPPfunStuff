#include<iostream>
#include<iomanip>
#include <vector>

//Custom matrix classes below
#include "upTriangMat.h"
#include "backWardSubstitution.h"
#include "QRdecompose.h"

int main()
{
    // std::vector<std::vector<double>> A = {
    //     {-4, 3, -4, 20},
    //     {2, -2, 1, -9},
    //     {-3, -1, -1, -4}
    // };

    std::vector<std::vector<double>> A = {
        {1,-1,5},
        {-2,0,3},
        {2,-1,-7}
    };

    QRresult firstTry = QRdecompose(A);

    //  LUResult lu = LUdecompose(A);
    // GaussianResult triang = toUpperTriangular(A);
    // doBackwardSub(A);


    return 0;
}
