#include "matrixal.hpp"
#include <iostream>

namespace matrixal {
    int maxMatrixElement(int n, int matrix[N_Max][N_Max]) {
        int maximum = matrix[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                maximum = std::max(maximum, matrix[i][j]);
            }
        }
        return maximum;
    }
    int minMatrixElement(int n, int matrix[N_Max][N_Max]) {
        int minimum = matrix[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                minimum = std::min(minimum, matrix[i][j]);
            }
        }
        return minimum;
    }
    int sumOfDigits(int number) {
        int sum = 0;
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
    void columnSort(int n, int (&matrix)[N_Max][N_Max]) {
        int columnOrder[N_Max], columnSum[N_Max];
        for (int j = 0; j < n; ++j) {
            columnOrder[j] = j;
            columnSum[j] = 0;
            for (int i = 0; i < n; ++i) {
                columnSum[j] += matrix[i][j];
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (columnSum[i] > columnSum[j]) {
                    std::swap(columnSum[i], columnSum[j]);
                    std::swap(columnOrder[i], columnOrder[j]);
                }
            }
        }
        int sortedMatrix[N_Max][N_Max];
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                sortedMatrix[i][j] = matrix[i][columnOrder[j]];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = sortedMatrix[i][j];
            }
        }
    }

}
