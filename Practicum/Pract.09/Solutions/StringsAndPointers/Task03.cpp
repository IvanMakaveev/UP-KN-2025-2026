#include <iostream>
const size_t MAX_SIZE = 1024;

size_t strLen(const char* str) {
    if (!str) {
        return 0;
    }

    size_t result = 0;

    while (*str) {
        result++;
        str++;
    }

    return result;
}

void substring(const char* str, size_t beg, size_t end, char* result) {
    if (!str || !result) {
        return;
    }

    size_t length = strLen(str);

    if (beg >= length) {
        *result = '\0';
        return;
    }

    if (end >= length) {
        end = length - 1;
    }

    str += beg;

    while (beg <= end) {
        *result = *str;
        result++;
        str++;
        beg++;
    }

    *result = '\0';
}

int main()
{
    char str[MAX_SIZE];
    size_t beg, end;
    char result[MAX_SIZE];

    std::cin >> str >> beg >> end;

    substring(str, beg, end, result);
    std::cout << result;
}

