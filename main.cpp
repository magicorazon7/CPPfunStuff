#include<iostream>
#include<iomanip>
#include <vector>
#include "LUdecompose.h"
#include "upTriangMat.h"
#include "backWardSubstitution.h"

int main()
{

    std::vector<std::vector<double>> A = {
        {-4, 3, -4, 20},
        {2, -2, 1, -9},
        {-3, -1, -1, -4}
    };



  //  LUResult lu = LUdecompose(A);
    GaussianResult triang = toUpperTriangular(A);
    doBackwardSub(A);


    return 0;
    //techindetail.com
}
