#pragma once
#include <iostream>

namespace matrixal {
    const int N_Max = 101;
    int sumOfDigits(int number);
    int maxMatrixElement(int n, int matrix[N_Max][N_Max]);
    int minMatrixElement(int n, int matrix[N_Max][N_Max]);
    void columnSort(int n, int (&matrix)[N_Max][N_Max]);
}
