#include <iostream>
const size_t MAX_SIZE = 1024;
const size_t LETTERS_COUNT = 26;

int getIndexFromSymbol(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    }

    return -1;
}

char getSymbolFromIndex(int index) {
    return index + 'a';
}

void sortCharacters(const char* str, char* result) {
    if (!str) {
        *result = '\0';
        return;
    }

    int count[LETTERS_COUNT]{ 0 };

    while (*str) {
        int index = getIndexFromSymbol(*str);
        if (index != -1) {
            count[index]++;
        }

        str++;
    }

    for (size_t i = 0; i < LETTERS_COUNT; i++) {
        int currentCount = count[i];

        if (currentCount == 0) {
            continue;
        }

        char currentSymbol = getSymbolFromIndex(i);

        while (currentCount--) {
            *result = currentSymbol;
            result++;
        }
    }

    *result = '\0';
}

int main()
{
    const char* str = "Programming123!";
    char result[MAX_SIZE];

    sortCharacters(str, result);
    std::cout << result;
}
