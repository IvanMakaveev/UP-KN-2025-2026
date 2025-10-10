#include <iostream>

int main() {
    int n;
    std::cin >> n;

    bool isOne = (n >= 0 && n <= 9);
    bool isTwo = (n >= 10 && n <= 99);
    bool isOther = (n >= 100);

    int result = isOne * n + isTwo * ((n % 10) + 1) + isOther * (n / 10);

    std::cout << result << std::endl;
}