#include <iostream>

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

unsigned int fromKToDecimal(const char arr[], size_t size, unsigned int K) {
    unsigned int result = 0;
    unsigned int multiplier = 1;

    for (int i = size - 1; i >= 0; i--) {
        int value = getIndexOfSymbol(arr[i]);
        if (value < 0 || value >= (int)K) {
            std::cout << "Invalid digit in base " << K << " number.\n";
            return 0;
        }
        result += value * multiplier;
        multiplier *= K;
    }

    return result;
}

bool areNumbersEqual(
    const char first[], size_t firstSize, unsigned int K,
    const char second[], size_t secondSize, unsigned int N
) {
    unsigned int firstDecimal = fromKToDecimal(first, firstSize, K);
    unsigned int secondDecimal = fromKToDecimal(second, secondSize, N);

    return firstDecimal == secondDecimal;
}

int main() {
    const size_t FIRST_SIZE = 3;
    const size_t SECOND_SIZE = 2;
    char first[] = { '3', '4', '5' };
    char second[] = { 'E', '5' };

    std::cout << areNumbersEqual(first, FIRST_SIZE, 8, second, SECOND_SIZE, 16);
}

