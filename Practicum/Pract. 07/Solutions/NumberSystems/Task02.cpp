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

void incrementKNumber(char arr[], size_t size, int K) {
    bool addOne = 1;

    for (int i = size - 1; i >= 0; i--) {
        int value = getIndexOfSymbol(arr[i]) + addOne;

        if (value >= K) {
            arr[i] = getSymbolFromIndex(value % K);
            addOne = 1;
        }
        else {
            arr[i] = getSymbolFromIndex(value);
            addOne = 0;
            break;
        }
    }

    // If carry remains after most significant digit
    if (addOne) {
        arr[0] = '1'; // assumes array has enough space
    }
}

void printArray(const char arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i];
    }

    std::cout << std::endl;
}

int main() {
    const size_t SIZE = 3;
    char arr[3] = { '0','1','1' };

    int K = 2;

    std::cout << "Before increment: ";
    printArray(arr, SIZE);

    incrementKNumber(arr, SIZE, K);

    std::cout << "After increment:  ";
    printArray(arr, SIZE);

    return 0;
}
