#include <iostream>

int main() {
    int apples, pears, bananas;

    std::cout << "Apples: ";
    std::cin >> apples;
    std::cout << "Pears: ";
    std::cin >> pears;
    std::cout << "Bananas: ";
    std::cin >> bananas;

    std::cout << "Pesho, don't forget to buy " << apples << " apples, "
        << pears << " pears and " << bananas << " bananas!";
}