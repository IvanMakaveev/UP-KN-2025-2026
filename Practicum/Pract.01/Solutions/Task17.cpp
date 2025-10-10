#include <iostream>

int main() {
    int a, b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    bool isFirstHigher = a > b;

    std::cout << "Max: " << a * isFirstHigher + b * !isFirstHigher << std::endl;
    std::cout << "Min: " << a * !isFirstHigher + b * isFirstHigher << std::endl;
}