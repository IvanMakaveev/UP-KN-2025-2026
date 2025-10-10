#include <iostream>

int main() {
    int amount;
    std::cout << "Enter amount in lv:";
    std::cin >> amount;
    std::cout << "This amount is " << amount * 0.5 << " in USD and " << amount * 0.51 << " in EUR." << std::endl;
}