#include <iostream>
#include <fstream>

int main() {
    int N;
    std::cin >> N;
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string curString;
    std::string vowelConsonantStrings[11000];
    int numberOfVowelConsonantStrings = 0;
    while (in >> curString) {
        int curVowelNumber = 0, curConsonantNumber = 0;
        for (int i = 0; i < curString.length(); ++i) {
            if (curString[i] == 'a' || curString[i] == 'e' || curString[i] == 'i' || curString[i] == 'o' || curString[i] == 'u'
            || curString[i] == 'y') {
                ++curVowelNumber;
            }
            else {
                ++curConsonantNumber;
            }
        }
        if (curConsonantNumber == curVowelNumber) {
            vowelConsonantStrings[numberOfVowelConsonantStrings] = curString;
            ++numberOfVowelConsonantStrings;
        }
    }
    if (numberOfVowelConsonantStrings == 0) {
        std::cout << "No one word with the same number of vowels and consonants.\n";
        return 0;
    }
    for (int i = 0; i < numberOfVowelConsonantStrings - 1; ++i) {
        for (int j = i + 1; j < numberOfVowelConsonantStrings; ++j) {
            if ((vowelConsonantStrings[i].length() < vowelConsonantStrings[j].length()) ||
                    (vowelConsonantStrings[i].length() == vowelConsonantStrings[j].length() && vowelConsonantStrings[i] < vowelConsonantStrings[j])) {
                std::swap(vowelConsonantStrings[i], vowelConsonantStrings[j]);
            }
        }
    }
    int numberOfDifferentVowelConsonantStrings = 1;
    std::string differentVowelConsonantStrings[N];
    differentVowelConsonantStrings[0] = vowelConsonantStrings[0];
    for (int i = 1; i < numberOfVowelConsonantStrings && numberOfDifferentVowelConsonantStrings < N; ++i) {
        if (differentVowelConsonantStrings[numberOfDifferentVowelConsonantStrings - 1] != vowelConsonantStrings[i]) {
            differentVowelConsonantStrings[numberOfDifferentVowelConsonantStrings] = vowelConsonantStrings[i];
            ++numberOfDifferentVowelConsonantStrings;
        }
    }
    if (numberOfDifferentVowelConsonantStrings < N) {
        std::cout << "No " << N << " different words with the same number of vowels and consonants.\n";
    } else {
        for (int i = 0; i < N; ++i) {
            out << differentVowelConsonantStrings[i] << "\n";
        }
    }
}


