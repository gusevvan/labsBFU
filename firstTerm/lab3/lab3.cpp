#include <iostream>

int main() {
    int A;
    std::cin >> A;
    int mult_end_2, maximum = A, number = 1, cur_number = 1;
    if (A % 10 == 2) {
        mult_end_2 = A;
    } else {
        mult_end_2 = 1;
    }
    while (std::cin >> A) {
        ++cur_number;
        if (A % 10 == 2) {
            mult_end_2 *= A;
        }
        if (A > maximum) {
            maximum = A;
            number = cur_number;
        }
    }
    if (mult_end_2 == 1) {
        std::cout << "No one number ending 2. ";
    } else {
        std::cout << mult_end_2 << " ";
    }
    std::cout << maximum << " " << number << "\n";
}
