#include <iostream>
#include <cstring>

class String {
private:
    char *_str = nullptr;
    int _size = 0;
public:
    String() = default;

    String(char *text) {
        _size = strlen(text);
        _str = new char[_size];
        std::copy(text, text + _size + 1, _str);
    }

    String(const String &other) {
        _size = other._size;
        _str = new char[_size];
        std::copy(other._str, other._str + _size + 1, _str);
    }

    String &operator=(const String &other) {
        if (_str != nullptr) {
            delete[] _str;
        }
        _size = other._size;
        _str = new char[_size];
        std::copy(other._str, other._str + _size + 1, _str);
    }

    String &operator=(char *text) {
        if (_str != nullptr) {
            delete[] _str;
        }
        _size = strlen(text);
        _str = new char[_size];
        std::copy(text, text + _size + 1, _str);
        return *this;
    }

    friend String operator+(const String& first, const String &second) {
        String result;
        result._size = first._size + second._size;
        result._str = new char[result._size];
        std::copy(first._str, first._str + first._size, result._str);
        std::copy(second._str, second._str + second._size + 1, result._str + first._size);
        return result;
    }

    String operator+=(const String &other) {
        return *this + other;
    }

    char &operator[](int i) {
        return this->_str[i];
    }

    bool operator<(const String &other) {
        for (int i = 0; i < std::min(this->_size, other._size); ++i) {
            if (this->_str[i] < other._str[i]) {
                return true;
            }
            if (this->_str[i] > other._str[i]) {
                return false;
            }
        }
        if (this->_size < other._size) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(const String &other) {
        for (int i = 0; i < std::min(this->_size, other._size); ++i) {
            if (this->_str[i] > other._str[i]) {
                return true;
            }
            if (this->_str[i] < other._str[i]) {
                return false;
            }
        }
        if (this->_size > other._size) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const String &other) {
        if (this->_str != other._str) {
            return false;
        }
        bool result = true;
        for (int i = 0; i < this->_size; ++i) {
            if (this->_str[i] != other._str[i]) {
                result = false;
            }
        }
        return result;
    }

    friend std::ostream &operator<<(std::ostream &out, const String &str) {
        out << str._str;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, String &str) {
        char text[100000];
        in >> text;
        str = text;
        return in;
    }

    int find(char symbol) {
        int result = -1;
        for (int i = 0; i < _size; ++i) {
            if (_str[i] == symbol) {
                result = i;
                break;
            }
        }
        return result;
    }

    int length() {
        return _size;
    }

    const char *c_str() {
        return _str;
    }

    char at(int i) {
        if (i >= _size) {
            throw 3;
        } else {
            return this->_str[i];
        }
    }

    ~String() {
        if (_str != nullptr) {
            delete[] _str;
        }
    }
};

int main() {
    try {
        int a = 10;
        String test1, test2 = "ghdl";
        std::cin >> test1;
        String res = test1 + test2;
        std::cout << res << "\n";
        std::cout << res[0] << "\n";
        res[0] = 'k';
        std::cout << res << "\n";
    } catch (int error) {
        if (error == 3) {
            std::cout << "Out of range\n";
        }
    }
}
