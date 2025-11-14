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

void decrementKNumber(char arr[], size_t size, int K) {
    bool subtractOne = 1; // start by subtracting 1

    for (int i = size - 1; i >= 0; i--) {
        int value = getIndexOfSymbol(arr[i]) - subtractOne;

        if (value < 0) {
            arr[i] = getSymbolFromIndex(value + K); // borrow from next digit
            subtractOne = 1; // continue borrowing
        }
        else {
            arr[i] = getSymbolFromIndex(value); // update digit
            subtractOne = 0; // no more borrow 
            break;
        }
    }
}

void printArray(const char arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i];
    }

    std::cout << std::endl;
}

int main()
{
    const size_t SIZE = 3;
    char arr[3] = { '1','0','0' };
    int K = 2;

    std::cout << "Before decrement: ";
    printArray(arr, SIZE);

    decrementKNumber(arr, SIZE, K);

    std::cout << "After decrement:  ";
    printArray(arr, SIZE);

    return 0;
}

