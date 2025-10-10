#include<iostream>

int main() {
    double x, y;

    std::cout << "First side: ";
    std::cin >> x;

    std::cout << "Second side: ";
    std::cin >> y;

    std::cout << "Parameter: " << 2 * (x + y) << std::endl;
    std::cout << "Area: " << x * y << std::endl;
}