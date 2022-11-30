#include <iostream>
#include "reading.hpp"

namespace reading {
    void read(int n, int matrix[N_Max][N_Max]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }
}
