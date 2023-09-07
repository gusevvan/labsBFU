#include <iostream>


int main() {
    int n;
    std::cin >> n;
    int a[n], multOfDigits[n], firstDigit[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int current =  a[i], currentMultOfDigits = 1;
        while (current > 0) {
            currentMultOfDigits *= current % 10;
            if (current < 10) {
                firstDigit[i] = current;
            }
            current /= 10;
        }
        multOfDigits[i] = currentMultOfDigits;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((multOfDigits[i] > multOfDigits[j]) || (multOfDigits[i] == multOfDigits[j] && firstDigit[i] > firstDigit[j]) ||
                        (multOfDigits[i] == multOfDigits[j] && firstDigit[i] == firstDigit[j] && a[i] > a[j])) {
                std::swap(multOfDigits[i], multOfDigits[j]);
                std::swap(firstDigit[i], firstDigit[j]);
                std::swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }

}
