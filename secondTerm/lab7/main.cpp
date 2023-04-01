#include <iostream>
#include <vector>
#include <cmath>

#define PI acos(-1)

enum Color {White, Black, Red, Green, Yellow, Blue, Orange, Grey, Purple};

class Shape {
protected:
	double _px, _py;
	Color _sColor;
public:
	virtual double area() {
		return 0;
	}
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

	double area() override {
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

	double area() override {
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

	double area() override {
		return _aScale * _bScale;
	}
};

int main()
{
	Shape* circle = new Circle(1, 1, 1, Blue);
	Shape* rectangle = new Rectangle(1, 1, 1, 1, Grey);
	Shape* triangle = new Triangle(1, 1, 1, 1, 1, White);
	std::vector<Shape*> shapes;
	shapes.push_back(circle);
	shapes.push_back(rectangle);
	shapes.push_back(triangle);
	for (Shape* shape:shapes) {
		std::cout << shape->area() << " ";
	}
	return 0;
}
