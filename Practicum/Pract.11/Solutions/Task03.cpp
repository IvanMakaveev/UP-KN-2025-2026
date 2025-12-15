#include <iostream>

void myStrCpy(char* destination, const char* source, size_t len) {
    if (!destination || !source) {
        return;
    }

    for (size_t i = 0; i < len; i++) {
        destination[i] = source[i];
    }

    destination[len] = '\0';
}

size_t countWords(const char* text, char s) {
    if (!text || text[0] == '\0') {
        return 0;
    }

    size_t count = 1;
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] == s) {
            count++;
        }
    }

    return count;
}

void splitText(const char* text, char s, char**& result, size_t& wordCount) {
    if (!text) {
        result = nullptr;
        wordCount = 0;
        return;
    }

    wordCount = countWords(text, s);
    result = new char* [wordCount];

    const char* start = text;
    size_t wordIndex = 0;

    while (*text) {
        if (*text == s) {
            size_t len = text - start;  // length of current word
            result[wordIndex] = new char[len + 1];
            myStrCpy(result[wordIndex], start, len);
            wordIndex++;
            start = text + 1;
        }
        text++;
    }

    // last word
    size_t len = text - start;
    result[wordIndex] = new char[len + 1];
    myStrCpy(result[wordIndex], start, len);
}


void freeMatrix(char** matrix, size_t wordCount) {
    for (size_t i = 0; i < wordCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printWords(const char* const* words, size_t wordCount) {
    for (size_t i = 0; i < wordCount; i++) {
        std::cout << words[i] << std::endl;
    }
}

int main() {
    char** words;
    size_t wordCount;

    splitText("Hello:my:name:is", ':', words, wordCount);

    printWords(words, wordCount);

    freeMatrix(words, wordCount);
}
