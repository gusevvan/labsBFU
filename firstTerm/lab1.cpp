#include <iostream>
#include <cmath>

#define PI acos(-1)

int main() {
    float a, A, B;
    std::cin >> a >> A >> B;
    a = a * PI / 180.0;
    std::cout << 1.0 / 2.0 * sin(a) * A * B << "\n";
}
