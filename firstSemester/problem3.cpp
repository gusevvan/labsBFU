#include <iostream>
#include <fstream>
#include <cstdio>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    char current;
    std::string currentWord;
    while(in.get(current)) {
        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) {
            currentWord += current;
        } else {
            if (currentWord.size() != 0) {
                bool isLetterInWord[32];
                for (int i = 0; i < 32; ++i) {
                    isLetterInWord[i] = false;
                }
                for (int i = 0; i < currentWord.size(); ++i) {
                    if (currentWord[i] >= 'A' && currentWord[i] <= 'Z') {
                        isLetterInWord[currentWord[i] - 'A'] = true;
                    } else {
                        isLetterInWord[currentWord[i] - 'a'] = true;
                    }
                }
                short numberOfDifferent = 0;
                for (int i = 0; i < 32; ++i) {
                    if (isLetterInWord[i]) {
                        ++numberOfDifferent;
                    }
                }
                if (numberOfDifferent > 7) {
                    out << '*' << currentWord << '*' << '(';
                    for (int i = 0; i < 32; ++i) {
                        if (isLetterInWord[i]) {
                            out << (char)(i + 'a');
                        }
                    }
                    out << ')';
                } else {
                    out << currentWord;
                }
                currentWord.clear();
            }
            out << current;
        }
    }
}
