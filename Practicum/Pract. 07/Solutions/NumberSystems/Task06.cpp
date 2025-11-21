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

void fromDecimalToN(unsigned int decimal, char to[], size_t size, unsigned int N) {
    for (int i = size - 1; i >= 0; i--) {
        int index = decimal % N;
        char current = getSymbolFromIndex(index);
        to[i] = current;
        decimal /= N;
    }
}

void printWithoutLeadingZeros(const char arr[], size_t size) {
    size_t start = 0;

    // Find first non-zero character
    while (start < size && arr[start] == '0') {
        start++;
    }

    // If all digits are zero, print '0'
    if (start == size) {
        std::cout << '0';
    }
    else {
        for (size_t i = start; i < size; i++) {
            std::cout << arr[i];
        }
    }

    std::cout << std::endl;
}

int main()
{
    unsigned int num = 167;
    unsigned int base = 12;
    char result[SIZE];

    fromDecimalToN(num, result, SIZE, base);
    printWithoutLeadingZeros(result, SIZE); // Output: 11B

    return 0;
}
