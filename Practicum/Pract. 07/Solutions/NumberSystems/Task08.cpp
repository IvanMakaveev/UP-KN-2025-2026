#include <iostream>
constexpr size_t SIZE = 50;

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

unsigned int fromKToDecimal(const char from[], size_t size, unsigned int K) {
    unsigned int result = 0;
    int multi = 1;

    for (int i = size - 1; i >= 0; i--) {
        result += (getIndexOfSymbol(from[i]) * multi);
        multi *= K;
    }

    return result;
}

void fromDecimalToN(unsigned int decimal, char to[], size_t size, unsigned int N) {
    for (int i = size - 1; i >= 0; i--) {
        int index = decimal % N;
        char current = getSymbolFromIndex(index);
        to[i] = current;
        decimal /= N;
    }
}

void fromKToN(const char from[], size_t fromSize, unsigned int K, char to[], size_t toSize, unsigned int N) {
    unsigned int decimal = fromKToDecimal(from, fromSize, K);
    fromDecimalToN(decimal, to, toSize, N);
}

void from12BaseTo13Base(const char from[], size_t fromSize, char to[], size_t toSize) {
    fromKToN(from, fromSize, 12, to, toSize, 13);
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

bool isValidSymbol(char c, int base) {
    int value = getIndexOfSymbol(c);
    return value >= 0 && value < base;
}

bool readArray(char arr[], size_t size, unsigned int base) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];

        if (!isValidSymbol(arr[i], base)) {
            return false;
        }
    }
    return true;
}

int main()
{
    size_t size;
    std::cin >> size;

    if (size < 1 || size > SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    char arr[SIZE];

    if (!readArray(arr, size, 12)) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    char result[SIZE];
    from12BaseTo13Base(arr, size, result, SIZE);
    printWithoutLeadingZeros(result, SIZE);

    return 0;
}
