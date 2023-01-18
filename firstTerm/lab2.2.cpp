#include <iostream>

int main() {
    int N;
    std::cin >> N;
    switch (N) {
        case 0:
            std::cout << "All good!\n";
            break;
        case 1:
            std::cout << "File reading error.\n";
            break;
        case 2:
            std::cout << "File writing error.\n";
            break;
        case 3:
            std::cout << "Error: Not all field defined.\n";
            break;
        default:
            std::cout << "Unknown error.";
    }
}
