#include <iostream>

bool isLower(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

bool isUpper(char symbol) {
    return symbol >= 'A' && symbol <= 'Z';
}

void toUpper(char& symbol) {
    if (isLower(symbol)) {
        symbol += 'A' - 'a';
    }
}

void toLower(char& symbol) {
    if (isUpper(symbol)) {
        symbol += 'a' - 'A';
    }
}

int main()
{
    char c = 'H';
    toLower(c);
    std::cout << c << std::endl;

    toUpper(c);
    std::cout << c << std::endl;
}

