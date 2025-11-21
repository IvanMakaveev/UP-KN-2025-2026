#include <iostream>
constexpr size_t SIZE = 32;

int getIndexOfSymbol(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'Z') {
        return 10 + c - 'A';
    }

    return -1;
}

char getSymbolFromIndex(int index) {
    if (index >= 0 && index <= 9) {
        return index + '0';
    }
    else if (index >= 10 && index < 36) {
        return index + 'A' - 10;
    }

    return '\0';
}

bool isPalindrome(const char arr[], size_t size) {
    // Skip leading zeros
    size_t start = 0;
    while (start < size && arr[start] == '0') {
        start++;
    }

    // If all characters are '0', it's a palindrome
    if (start == size) {
        return true;
    }

    size_t end = size - 1;

    while (start < end) {
        if (arr[start] != arr[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

void fromDecimalToN(unsigned int decimal, char to[], size_t size, unsigned int N) {
    for (int i = size - 1; i >= 0; i--) {
        int index = decimal % N;
        char current = getSymbolFromIndex(index);
        to[i] = current;
        decimal /= N;
    }
}

bool isNumberPalindrome(unsigned int number, unsigned int base) {
    if (base < 2 || base > 16) {
        return false;
    }

    char representation[SIZE];
    fromDecimalToN(number, representation, SIZE, base);

    return isPalindrome(representation, SIZE);
}

int main() {
    unsigned int number, base;
    std::cin >> number >> base;

    if (isNumberPalindrome(number, base)) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
