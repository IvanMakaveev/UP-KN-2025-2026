#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    for (int i = 1; i < number; i++) {
        int x = i;
        int y = number - x;

        std::cout << "x = " << x << " y = " << y << std::endl;
    }
}
