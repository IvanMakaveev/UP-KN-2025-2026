#include <iostream>
constexpr size_t SIZE = 8;

int binaryToDecimal(const char binary[], size_t size) {
    unsigned int result = 0;
    unsigned int multi = 1; 

    for (int i = size - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            result += multi;
        }
        multi *= 2;
    }

    return result;
}

void decimalToBinary(unsigned int decimal, char binary[], size_t size) {
    for (int i = size - 1; i >= 0; i--) {
        binary[i] = (decimal % 2) ? '1' : '0';
        decimal /= 2;
    }
}

void negate8BitBinary(const char input[], char output[]) {
    int decimal = binaryToDecimal(input, SIZE);
    decimal *= -1;

    // If the result is negative, add 256 to wrap it around
    // into the 8-bit unsigned range (0–255). 
    // This effectively simulates two’s complement representation,
    // where negative numbers are stored as their value modulo 256.
    // Example:
    //  10  ->  00001010
    // -10  ->  11110110  (because -10 + 256 = 246)
    //  -1  ->  11111111  (because -1  + 256 = 255)
    if (decimal < 0) {
        decimal += 256;
    }

    decimalToBinary(decimal, output, SIZE);
}

int main()
{
    char input[SIZE];
    char output[SIZE];

    for (size_t i = 0; i < SIZE; i++) {
        std::cin >> input[i];
        if (input[i] != '0' && input[i] != '1') {
            std::cout << "Invalid input" << std::endl;
            return 0;
        }
    }

    negate8BitBinary(input, output);

    for (size_t i = 0; i < SIZE; i++) {
        std::cout << output[i];
    }
    std::cout << std::endl;

    return 0;
}

