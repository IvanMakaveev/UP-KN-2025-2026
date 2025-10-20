#include <iostream>

int main() {
    int n;
    char symbol;
    std::cin >> n >> symbol;

    if (n < 2 || n > 9) {
        std::cout << "Invalid input. N must be between 2 and 9." << std::endl;
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        int spaces = n - i;
        int symbols = 2 * i - 1;

        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }

        for (int j = 0; j < symbols; j++) {
            std::cout << symbol;
        }

        std::cout << std::endl;
    }

    for (int i = n - 1; i >= 1; i--) {
        int spaces = n - i;
        int symbols = 2 * i - 1;

        for (int j = 0; j < spaces; j++) {
            std::cout << " ";
        }

        for (int j = 0; j < symbols; j++) {
            std::cout << symbol;
        }

        std::cout << std::endl;
    }

    return 0;
}