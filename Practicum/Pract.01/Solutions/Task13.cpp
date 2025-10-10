#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int x1, x2, y1, y2;
    std::cout << "x1: ";
    std::cin >> x1;
    std::cout << "y1: ";
    std::cin >> y1;
    std::cout << "x2: ";
    std::cin >> x2;
    std::cout << "y2: ";
    std::cin >> y2;

    double distance = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    std::cout << "Distance: " << std::fixed << std::setprecision(2) << distance;
}