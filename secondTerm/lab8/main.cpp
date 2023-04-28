#include <iostream>
#include <stack>

template <typename T>
struct element {
	T value;
	element* previous;
};

template <typename T>
class Stack {
private:
	int _size = 0;
	element<T>* _last = nullptr;
public:
	bool empty() {
		return (_size == 0 ? true : false);
	}

	void push(T value) {
		++_size;
		element<T>* current = new element<T>;
		if (current == NULL) {
			throw std::bad_alloc();
		}
		current->value = value;
		current->previous = _last;
		_last = current;
	}

	void pop() {
		if (_size == 0) {
			throw std::out_of_range("Stack is empty");
		}
		else {
			--_size;
			if (_size == 0) {
				delete[] _last;
				_last = nullptr;
			}
			else {
				element<T>* current = new element<T>;
				current->value = (_last->previous)->value;
				current->previous = (_last->previous)->previous;
				delete[] _last;
				_last = current;
			}
		}
	}

	T top() {
		if (_size == 0) {
			throw std::logic_error("Stack is empty");
		}
		else {
			return _last->value;
		}
	}

	int size() {
		return _size;
	}

	~Stack() {
		while (_size > 1) {
			--_size;
			element<T>* current = new element<T>;
			current->value = (_last->previous)->value;
			current->previous = (_last->previous)->previous;
			delete[] _last;
			_last = current;
		}
		if (_size == 1) {
			delete[] _last;
			_last = nullptr;
		}
	}
};

int main() {
	try {
		Stack<int> test;
		for (int i = 255; i < 265; ++i) {
			test.push(i);
		}
		std::cout << test.size() << "\n";
		for (int i = 0; i < 10; ++i) {
			std::cout << test.size() << " " << test.top() << "\n";
			test.pop();
		}
		std::cout << test.size() << "\n";
		test.push(15);
		std::cout << test.size() << " " << test.top() << "\n";
	}
	catch (const std::error_code& error) {
		std::cout << error << "\n";
	}
}
