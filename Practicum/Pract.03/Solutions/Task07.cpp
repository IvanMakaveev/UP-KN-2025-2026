#include <iostream>

int main()
{
    int left, right;
    std::cin >> left >> right;

    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    for (int i = left; i <= right; i++) {
        std::cout << (char)i << std::endl;;
    }
}
