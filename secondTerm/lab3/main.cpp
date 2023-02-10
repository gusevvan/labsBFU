#include <iostream>

class Complex {
private:
	double _re = 0;
	double _im = 0;
public:
	Complex() = default;

	Complex(double newRe, double newIm) {
		_re = newRe;
		_im = newIm;
	}

	void operator=(const Complex& number) {
		_re = number._re;
		_im = number._im;
	}

	Complex& operator+=(const Complex& number) {
		_re += number._re;
		_im += number._im;
		return *this;
	}

	Complex& operator*=(const Complex& number) {
		int tempRe = _re;
		_re = _re * number._re - _im * number._im;
		_im = tempRe * number._im + _im * number._re;
		return *this;
	}

	Complex& operator++() {
		_re++;
		return *this;
	}

	Complex operator++(int) {
		Complex temp = *this;
		_re++;
		return temp;
	}

	friend std::istream& operator>>(std::istream& in, Complex& number) {
		in >> number._re >> number._im;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Complex& number) {
		out << "(" << number._re << "," << number._im << ")";
		return out;
	}

};

Complex operator+(const Complex& number1, const Complex& number2) {
	Complex result = number1;
	return result += number2;
}

Complex operator*(const Complex& number1, const Complex& number2) {
	Complex result = number1;
	return result *= number2;
}

int main()
{
	Complex sample1(10, 4);
	Complex sample2;
	std::cin >> sample2;
	std::cout << sample1 + sample2 << "\n";
	std::cout << sample1 * sample2 << "\n";
	std::cout << sample1 << "\n";
	Complex sample3(1, 1);
	sample1 += sample3;
	std::cout << sample1 << "\n";
	sample1 *= sample3;
	std::cout << sample1 << "\n";
	std::cout << (sample2++) << "\n";
	std::cout << sample2 << "\n";
	std::cout << (++sample2) << "\n";
	std::cout << sample2 << "\n";
	int a;
}
