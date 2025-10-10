#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int k = n / 3; // count of positive multiples of 3 <= n
    int sum = 3 * k * (k + 1) / 2; // arithmetic series: 3*(1+2+...+k)

    std::cout << "The total sum is: " << sum << std::endl;
}