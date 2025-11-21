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

int main()
{
    
}
