#include <iostream>
#include <math.h>

int main() {
    int a, b, c;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    double d = std::sqrt(b * b - 4 * a * c);
    double x1 = (-b + d) / (2 * a);
    double x2 = (-b - d) / (2 * a);

    std::cout << "x1 = " << x1 << ", x2 = " << x2;
}