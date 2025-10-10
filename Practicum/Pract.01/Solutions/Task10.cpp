#include <iostream>

int main() {
    int a, b;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    int temp = a;
    a = b;
    b = temp;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}