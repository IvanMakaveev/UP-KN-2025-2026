#include <iostream>

int countOnesInBinary(int n) {
    int count = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }

        n /= 2;
    }

    return count;
}

int main()
{
    unsigned int number;
    std::cin >> number;

    std::cout << countOnesInBinary(number);
}
