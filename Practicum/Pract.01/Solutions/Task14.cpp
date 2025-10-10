#include <iostream>

int main() {
    long long cardNumber;
    std::cin >> cardNumber;

    std::cout << "XXXXXXXXXXXX" << cardNumber % 10000;
}