#include <iostream>

class paral{
    private:
        double first_side = 0;
        double second_side = 0;
    public:
        void setFirstSide(double size) {
            if (size < 0) {
                throw (1);
            }
            first_side = size;
        }
        void setSecondSide(double size) {
            if (size < 0) {
                throw (1);
            }
            second_side = size;
        }
        paral(double first, double second) {
            setFirstSide(first);
            setSecondSide(second);
        }
        int perimetr() {
            return (first_side + second_side) * 2;
        }
};

int main() {
    try {
        paral p1(10, 2);
        std::cout << p1.perimetr();
    }
    catch (int error) {
        std::cout << "Size error.";
    }
}
