#include <iostream>
#include <cmath>

#define PI acos(-1)

enum Color {White, Black, Red, Green, Yellow, Blue, Orange, Grey, Purple};

class Shape {
protected:
	double _px, _py;
	Color _sColor;
};

class Triangle : public Shape {
private:
	double _aScale, _bScale, _cScale;
public:
	Triangle(double a, double b, double c, double x, double y, Color color) {
		_aScale = a;
		_bScale = b;
		_cScale = c;
		_px = x;
		_py = y;
		_sColor = color;
	}

	double area() {
		double semiPerimeter = (_aScale + _bScale + _cScale) / 2;
		return std::sqrt(semiPerimeter * (semiPerimeter - _aScale) *
									(semiPerimeter - _bScale) * (semiPerimeter - _cScale));
	}
};

class Circle : public Shape {
private:
	double _radius;
public:
	Circle(double radius, double x, double y, Color color) {
		_radius = radius;
		_px = x;
		_py = y;
		_sColor = color;
	}

	double area() {
		return PI * _radius * _radius;
	}
};

class Rectangle : public Shape {
private:
	double _aScale, _bScale;
public:
	Rectangle(double a, double b, double x, double y, Color color) {
		_aScale = a;
		_bScale = b;
		_px = x;
		_py = y;
		_sColor = color;
	}

	double area() {
		return _aScale * _bScale;
	}
};

int main()
{
	Circle circle(1, 1, 1, Blue);
	std::cout << circle.area() << "\n";
	Rectangle rectangle(1, 1, 1, 1, Grey);
	std::cout << rectangle.area() << "\n";
	Triangle triangle(1, 1, 1, 1, 1, White);
	std::cout << triangle.area() << "\n";
	return 0;
}
