#include <iostream>

bool isPowerOfTwo(unsigned number) {
    if (number == 0) {
        return false;
    }

    int mask = number - 1; // Example: 8 (1000) - 1 = 7 (0111)

    return (number & mask) == 0; // 1000 & 0111 = 0 => power of two
}

int main()
{
    int num;
    std::cin >> num;

    std::cout << isPowerOfTwo(num) << std::endl;
}
