#include <iostream>
#include <cstring>

char *sum(char A[2002], char B[2002]) {
    char reversedSum[2002];
    int current = 0, currentCharA = strlen(A) - 1, currentCharB = strlen(B) - 1, remainder = 0;
    while (currentCharA >= 0 || currentCharB >= 0) {
        int sumChar = 0;
        if (currentCharA >= 0) {
            sumChar += A[currentCharA] - '0';
            --currentCharA;
        }
        if (currentCharB >= 0) {
            sumChar += B[currentCharB] - '0';
            --currentCharB;
        }
        sumChar += remainder;
        remainder = sumChar / 10;
        reversedSum[current] = sumChar % 10 + '0';
        ++current;
    }
    if (remainder > 0) {
        reversedSum[current] = remainder + '0';
        ++current;
    }
    char* result = new char[2002];
    for (int i = 0; i < current; ++i) {
        result[i] = reversedSum[current - i - 1];
    }
    return result;
}

char *mult(char A[2002], char B[2002]) {
    if (strcmp("0", B) == 0) {
        return B;
    }
    char* result = new char[2002];
    for (int i = strlen(A) - 1; i >= 0; --i) {
        int currentDigit = A[i] - '0';
        char tmp[2002];
        strcpy(tmp, "0");
        for (int j = 0; j < currentDigit; ++j) {
            strcpy(tmp, sum(tmp, B));
        }
        for (int j = 0; j < strlen(A) - i - 1; ++j) {
            strcat(tmp, "0");
        }
        strcpy(result, sum(result, tmp));
    }
    return result;
}

int main() {
    char A[2002], B[2002];
    std::cin >> A >> B;
    std::cout << sum(A, B) << " " << mult(A, B);

}
