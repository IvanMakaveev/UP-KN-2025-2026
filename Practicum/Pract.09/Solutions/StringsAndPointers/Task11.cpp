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

char toLower(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

bool isPrefixIgnoreCase(const char* text, const char* substr) {
    if (!text || !substr) {
        return false;
    }

    while (*substr) {
        if (toLower(*text) != toLower(*substr)) {
            return false;
        }

        text++;
        substr++;
    }

    return true;
}

void replaceSubstringWithStars(const char* text, const char* substr, char* result) {
    if (!text || !substr) {
        if (result) {
            *result = '\0';
        }
        return;
    }

    size_t subLen = strlen(substr);

    while (*text) {
        if (isPrefixIgnoreCase(text, substr)) {
            for (size_t i = 0; i < subLen; i++) {
                *result = '*';
                result++;
            }

            text += subLen; 
        }
        else {
            *result = *text;
            result++;
            text++;
        }
    }

    *result = '\0';
}

int main() {
    const char* text = "Howdy! How are you? How was your day?";
    const char* substr = "how";

    char result[1024];
    replaceSubstringWithStars(text, substr, result);

    std::cout << result;
}
