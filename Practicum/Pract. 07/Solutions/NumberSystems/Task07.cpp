#include <iostream>0

unsigned int ternaryToDecimal(unsigned int ternary) {
    unsigned int decimal = 0;
    unsigned int power = 1;

    while (ternary > 0) {
        unsigned int digit = ternary % 10;

        if (digit > 2) { // validate ternary digit
            std::cout << "Invalid ternary digit!" << std::endl;
            return 0;
        }

        decimal += digit * power;
        power *= 3;
        ternary /= 10;
    }

    return decimal;
}

void printDecimalAsOctal(unsigned int decimal) {
    if (decimal == 0) {
        std::cout << '0' << std::endl;
        return;
    }

    // Find highest power of 8
    unsigned int octalPower = 1;
    while (octalPower <= decimal / 8) {
        octalPower *= 8;
    }

    // Print octal digits
    while (octalPower > 0) {
        unsigned int digit = decimal / octalPower;
        std::cout << digit;
        decimal %= octalPower;
        octalPower /= 8;
    }

    std::cout << std::endl;
}

void ternaryToOctal(unsigned int ternary) {
    unsigned int decimal = ternaryToDecimal(ternary);
    printDecimalAsOctal(decimal);
}

int main()
{
    unsigned int ternaryNumber = 11120;
    ternaryToOctal(ternaryNumber); // Output: 173

    return 0;
}
