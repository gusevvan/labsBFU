#include <iostream>

template<typename T>
class vector {

};

template<>
class vector<bool> {
private:
    unsigned char* _content = new unsigned char(0);
    int _capacity = 1;
    int _size = 0;
    void updateMas() {
        unsigned char* tmp = _content;
        _capacity *= 2;
        _content = new unsigned char[_capacity];
        for (int i = 0; i  < _capacity; ++i) {
            _content[i] = 0;
        }
        for (int i = 0; i < _size; ++i) {
            _content[i] = tmp[i];
        }
        delete[] tmp;
    }
public:


    void push(bool element) {
        if (_capacity * 8 < _size + 1) {
            updateMas();
        }
        unsigned char charElement = element;
        charElement <<= (7 - _size % 8);
        _content[_size / 8] += charElement;
        ++_size;
    }

    void insert(int i, bool element) {
        if (_capacity * 8 < _size + 1) {
            updateMas();
        }
        unsigned char tmp1 = _content[i / 8] >> (8 - i % 8);
        tmp1 <<= (8 - i % 8);
        unsigned char tmp2 = (_content[i / 8] << (i % 8));
        tmp2 >>= (i % 8 + 1);
        unsigned char remainder = _content[i / 8] % 2;
        remainder <<= 7;
        unsigned char charElement = element;
        _content[i / 8] = tmp1 + tmp2 + (charElement << (7 - i % 8));
        for (int j = i / 8 + 1; j <= _size / 8; ++j) {
            unsigned char tmpRemainder = _content[j] % 2;
            _content[j] >>= 1;
            _content[j] += remainder;
            remainder = tmpRemainder << 7;
        }
        ++_size;
    }

    void erase(int i) {
        unsigned char remainder = 0;
        if (i / 8 < _size / 8) {
            remainder = _content[_size / 8] >> 7;
            _content[_size / 8] <<= 1;
            for (int j = _size / 8 - 1; j >= i / 8 + 1; --j) {
                unsigned char tmpRemainder = _content[j] >> 7;
                _content[j] = _content[j] << 1 + remainder;
                remainder = tmpRemainder;
            }
        }
        unsigned char tmp1 = _content[i / 8] << (i % 8 + 1);
        tmp1 >>= (i % 8);
        unsigned char tmp2 = _content[i / 8] >> (8 - i % 8);
        tmp2 <<= (8 - i % 8);
        _content[i / 8] = tmp1 + tmp2 + remainder;
        --_size;
    }

    bool get(int i) {
        return (_content[i / 8] >> (7 - i % 8)) % 2;
    }

    void change(int i, bool element) {
        unsigned char x = 255 - (1 << (7 - i % 8));
        _content[i / 8] &= x;
        unsigned char charElement = element;
        _content[i / 8] += (charElement << (7 - i % 8));
    }

    int size() {
        return _size;
    }

    void show() {
        for (int i = 0; i < _size / 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                std::cout << (_content[i] >> (7 - j)) % 2 << " ";
            }
        }
        for (int j = 0; j < _size % 8; ++j) {
            std::cout << (_content[_size / 8] >> (7 - j)) % 2 << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    vector<bool> test;
    test.push(0);
    test.push(1);
    test.push(1);
    test.push(0);
    test.push(1);
    test.erase(4);
    test.insert(0, 0);
    test.insert(5, 0);
    test.show();
    return 0;
}

