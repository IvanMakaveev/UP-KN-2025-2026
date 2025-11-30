#include <iostream>

size_t strlen(const char* str) {
    if (!str) {
        return 0;
    }

    size_t length = 0;

    while (*str) {
        length++;
        str++;
    }

    return length;
}

bool isPalindromeRange(const char* str, size_t start, size_t end) {
    if (!str) {
        return false;
    }

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int countPalindromicSubstrings(const char* str) {
    if (!str) {
        return 0;
    }

    size_t length = strlen(str);
    int count = 0;

    for (size_t i = 0; i < length; i++) {
        for (size_t j = i; j < length; j++) {

            if (isPalindromeRange(str, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    const char* str = "ababa";
    std::cout << countPalindromicSubstrings(str);
}
