#include <iostream>
constexpr size_t SIZE = 3;

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

bool addKNumbers(const char first[], const char second[], size_t size, unsigned int K, char result[]) {
    int carry = 0;

    // Start from right to left
    for (int i = size - 1; i >= 0; i--) {
        int firstDigit = getIndexOfSymbol(first[i]);
        int secondDigit = getIndexOfSymbol(second[i]);

        if (firstDigit == -1 || firstDigit >= K) {
            std::cout << "Invalid digit in first number!" << std::endl;
            return false;
        }

        if (secondDigit == -1 || secondDigit >= K) {
            std::cout << "Invalid digit in second number!" << std::endl;
            return false;
        }

        int sum = firstDigit + secondDigit + carry;
        result[i + 1] = getSymbolFromIndex(sum % K);
        carry = sum / K;
    }

    // Place the remaining carry at the first index
    result[0] = getSymbolFromIndex(carry);
    return true;
}

int main()
{
    char firstNumber[SIZE] = { '1', '7', '5' };
    char secondNumber[SIZE] = { '5', '3', '7' };
    char result[SIZE + 1]; // SIZE + 1 to store possible carry

    bool isSuccessful = addKNumbers(firstNumber, secondNumber, 3, 8, result);

    if (isSuccessful) {
        // Skip leading zero if there is no carry
        int startIndex = (result[0] == '0') ? 1 : 0;

        for (int i = startIndex; i < SIZE + 1; i++) {
            std::cout << result[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}

