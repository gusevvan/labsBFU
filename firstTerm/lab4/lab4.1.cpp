#include <iostream>
#include <cmath>

int main () {
    int n;
    std::cin >> n;
    int a[n];
    bool isSimleHere = false;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        bool isSimple;
        if (a[i] != 1) {
            isSimple = true;
        } else {
            isSimple = false;
        }
        for (int j = 2; j <= sqrt(a[i]); ++j) {
            if (a[i] % j == 0) {
                isSimple = false;
                break;
            }
        }
        if (isSimple) {
            isSimleHere = true;
        }
    }
    if (isSimleHere) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    std::swap(a[i], a[j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
}
