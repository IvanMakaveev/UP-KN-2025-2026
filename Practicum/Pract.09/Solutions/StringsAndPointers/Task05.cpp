#include <iostream>
const size_t MAX_SIZE = 1024;
const size_t SIZE = 26;

void deleteDuplicates(char* str) {
    if (!str) {
        return;
    }

    bool contains[SIZE]{ 0 };

    while (*str) {
        int index = *str - 'a';

        if (contains[index]) {
            char* p = str;
            while (*p) {
                *p = *(p + 1);
                p++;
            }
        }
        else {
            contains[index] = 1;
            str++;
        }
    }
}
int main()
{
    char str[MAX_SIZE];
    std::cin >> str;
    deleteDuplicates(str);
    std::cout << str;
}
