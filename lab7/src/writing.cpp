#include <iostream>
#include "writing.hpp"

namespace writing {
    void write(int n, int matrix[N_Max][N_Max]) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}
