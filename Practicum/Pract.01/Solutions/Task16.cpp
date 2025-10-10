#include <iostream>

int main() {
    int a, b;
    std::cout << "First number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "First number: " << a << std::endl;
    std::cout << "Second number: " << b << std::endl;
}