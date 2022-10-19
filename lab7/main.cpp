#include <iostream>
#include <math.h>
#include "reading.hpp"
#include "writing.hpp"
#include "matrixal.hpp"

using namespace writing;
using namespace reading;
using namespace matrixal;

int main() {
    int n;
    std::cin >> n;
    int matrix[101][101];
    read(n, matrix);
    if (abs(sumOfDigits(maxMatrixElement(n, matrix)) - sumOfDigits(minMatrixElement(n, matrix))) <= 2) {
        columnSort(n, matrix);
    }
    write(n, matrix);
}
