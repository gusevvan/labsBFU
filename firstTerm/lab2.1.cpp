#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    if (A > B && B > C) {
        std::cout << A - B - C << "\n";
    } else {
        if (B > A && B % C == 0) {
            std::cout << B / C + B - A << "\n";
        } else {
            std::cout << A + B + C << "\n";
        }
    }
}
