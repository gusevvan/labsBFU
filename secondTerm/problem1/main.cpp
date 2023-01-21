#include <iostream>
#include <vector>
#include <string>

class Cryptographer {
private:
    std::vector<std::string> _key;
    int _fib[31];
    int fib(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return fib(n - 1) + fib(n - 2);
    }
public:
    Cryptographer() {
        for (int i = 1; i <= 30; ++i) {
            _fib[i] = fib(i);
        }
    }
    void set(std::string newKey) {
        std::string curWord;
        for (int i = 0; i <= newKey.size(); ++i) {
            if (newKey[i] != ' ' && i < newKey.size()) {
                curWord += newKey[i];
            } else {
                _key.push_back(curWord);
                curWord.clear();
            }
        }
    }
    void show() const {
        for (int i = 0; i < _key.size(); ++i) {
            std::cout << _key[i] << " " << _fib[i + 1] << "\n";
        }
    }
    void enCode(const std::string& text) const {
        std::vector<int> out;
        std::string curWord;
        for (int i = 0; i <= text.size(); ++i) {
            if (text[i] != ' ' && i < text.size()) {
                curWord += text[i];
            } else {
                if (curWord.size() != 0) {
                    bool flag = false;
                    for (int i = 0; i < _key.size(); ++i) {
                        if (_key[i] == curWord) {
                            flag = true;
                            out.push_back(_fib[i + 1]);
                            curWord.clear();
                        }
                    }
                    if(!flag) {
                        std::cout << "Error!\n";
                        return;
                    }
                }
            }
        }
        for (int i:out) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    void deCode(const std::vector<int>& numbers) const {
        std::vector<std::string> out;
        for (int i = 0; i < numbers.size(); ++i) {
            bool flag = false;
            for (int j = 1; j < 31; ++j) {
                if (numbers[i] == _fib[j] && j <= _key.size()) {
                    out.push_back(_key[j - 1]);
                    flag = true;
                }
            }
            if (!flag) {
                std::cout << "Error!\n";
                return;
            }
        }
        for (std::string i:out) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Cryptographer sample;
    sample.set("abab baca adsjk asadjk");
    std::string test;
    sample.enCode("abab baca asadjk abab");
    sample.deCode({1, 3, 5});
    return 0;
}