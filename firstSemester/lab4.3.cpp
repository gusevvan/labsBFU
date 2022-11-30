#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    int firstNumberOfEven = 0;
    for (int j = 0; j < m; ++j) {
        if (a[0][j] % 2 == 0) {
            ++firstNumberOfEven;
        }
    }
    int minNumberOfEven = firstNumberOfEven, stringWithMinEven = 0;
    for (int i = 1; i < n; ++i) {
        int curEven = 0;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 == 0) {
                ++curEven;
            }
        }
        if (curEven < minNumberOfEven) {
            minNumberOfEven = curEven;
            stringWithMinEven = i + 1;
        }
    }
    for (int j = 0; j < m; ++j) {
        a[stringWithMinEven][j] *= a[stringWithMinEven][j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
}
