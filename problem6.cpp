#include <iostream>
#include <vector>

struct Item {
    int _a;
    int _b;
    int _c;
    Item(int a, int b, int c) {
        _a = a;
        _b = b;
        _c = c;
    }
};

int main() {
    std::vector<int> test = {1, 2, 3, 4};

    test.push_back(10); // в конец вектора добавлено число 10
    for (int element: test) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    test.erase(test.begin(), test.begin() + 2); // удаляет элементы в заданном диапозоне
    for (int element: test) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    test.insert(test.begin() + 1, 1, 55); // вставляет после указанной позиции значения
    for (int element: test) {
        std::cout << element << " ";
    }

    test.resize(10, 1); // дополняет вектор до размера 10 числами 1
    for (int element: test) {
        std::cout << element << " ";
    }
    std::cout << "\n";
    test.resize(5); // обрезает вектор до размера 5
    for (int element: test) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    std::vector<Item> emplaceTest;
    emplaceTest.emplace_back(1,2,3); // вставляет в конец вектора Item с значениями 1 2 и 3
    emplaceTest.push_back(Item(1,2,3));

    std::cout << test.capacity() << "\n"; // память выделяемая под вектор
    test.reserve(100); // увеличивает выделяемую под вектор память
    std::cout << test.capacity() << "\n";
    test.shrink_to_fit(); // очищает лишнюю память выделенную под вектор
    std::cout << test.capacity() << "\n";


    std::vector<int> tmp;
    tmp = test;
    for (int element: tmp) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    test.clear(); // полностью удаляет все элементы из вектора но не очищает память

    std::cout << test.size() << " " << test.capacity() << "\n";

    std::cout << tmp[3]; // выводит элемент tmp на 3 позиции
}
