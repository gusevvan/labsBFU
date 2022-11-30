#include <iostream>

void fill(unsigned char cell[3], unsigned char numbers[8]) {
    cell[0] &= ((numbers[0] << 5) | (numbers[1] << 2) | (numbers[2] >> 1));
    cell[1] &= ((numbers[2] << 7) | (numbers[3] << 4) | (numbers[4] << 1) | (numbers[5] >> 2));
    cell[2] &= ((numbers[5] << 6) | (numbers[6] << 3) | numbers[7]);
}

void pull(unsigned char cell[3], unsigned char numbers[8]) {
    numbers[0] = cell[0] >> 5;
    numbers[1] = (7 & (cell[0] >> 2));
    numbers[2] = ((3 & cell[0]) << 1) | (cell[1] >> 7);
    numbers[3] = (7 & cell[1] >> 4);
    numbers[4] = (7 & cell[1] >> 1);
    numbers[5] = ((cell[1] & 1) << 2) | (cell[2] >> 6);
    numbers[6] = (7 & (cell[2] >> 3));
    numbers[7] = (7 & cell[2]);
}


int main() {
    unsigned char inNumbers[8] = {5, 5, 3, 4, 7, 3, 2, 1};
    unsigned char cell[3] = {255, 255, 255};
    fill(cell, inNumbers);
    unsigned char outNumbers[8];
    pull(cell, outNumbers);
    for (int i = 0; i < 8; ++i) {
        std::cout << (int)outNumbers[i] << " ";
    }
}
