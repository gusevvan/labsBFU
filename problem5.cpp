#include <iostream>

class SmartMas {
    private:
        int* mas_ = new int;
        int size_ = 0;
        int capicity_ = 1;
        void updateMas() {
            int* tmp = mas_;
            capicity_ *= 2;
            mas_ = new int[capicity_];
            for (int i = 0; i < size_; ++i) {
                mas_[i] = tmp[i];
            }
            delete[] tmp;
        }
        void boundCheck(int index) {
            if (index > size_) {
                throw(1);
            }
        }
    public:
        void add(int index, int value) {
            boundCheck(index - 1);
            if (index > size_) {
                throw(1);
            }
            if (size_ + 1 > capicity_) {
                updateMas();
            }
            for (int i = size_; i > index; --i) {
                mas_[i] = mas_[i - 1];
            }
            mas_[index] = value;
            ++size_;
        }
        void del(int index) {
            boundCheck(index);
            for (int i = index; i < size_ - 1; ++i) {
                mas_[i] = mas_[i + 1];
            }
            --size_;
        }
        void push(int value) {
            add(size_, value);
        }
        int size() {
            return size_;
        }
        int get(int index) {
            boundCheck(index);
            return mas_[index];
        }
        void change(int index, int value) {
            boundCheck(index);
            mas_[index] = value;
        }
        int operator[] (int index) {
            return mas_[index];
        }
};

int main() {
    SmartMas a;
    try {

    }
    catch (int error) {
        std::cout << "Error: out of bounds.\n";
    }
}
