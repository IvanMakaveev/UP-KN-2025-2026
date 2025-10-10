#include<iostream>

int main() {
    double a, b;

    std::cout << "First number: ";
    std::cin >> a;

    std::cout << "Second number: ";
    std::cin >> b;

    std::cout << std::boolalpha << (a < b) << std::endl;
}