#include <iostream>

int main() {
    int number;
    std::cin >> number;
    int* x = &number;
    unsigned char* p = (unsigned char*)x;
    std::cout << int(*p) << " " << int(*(p + 1)) << " " << int(*(p + 2)) << " " << int(*(p + 3));
}
