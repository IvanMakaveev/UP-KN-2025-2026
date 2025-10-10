#include <iostream>

const double PI = 3.14159265;

int main() {
    double radius;

    std::cout << "Radius: ";
    std::cin >> radius;

    std::cout << "Perimeter: " << 2 * radius * PI << std::endl;
    std::cout << "Area: " << radius * PI * PI << std::endl;
}