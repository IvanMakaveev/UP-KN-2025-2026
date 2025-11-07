#include <iostream>
const size_t MAX_SIZE = 1000;

bool isValidSize(size_t size) {
    return size >= 0 && size <= MAX_SIZE;
}

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

bool isSubarray(const int first[], size_t firstSize, const int second[], size_t secondSize) {
    if (secondSize > firstSize) {
        return false;
    }

    for (size_t i = 0; i <= firstSize - secondSize; i++) {
        bool areEqual = true;

        for (int j = 0; j < secondSize; j++) {
            if (first[i + j] != second[j]) {
                areEqual = false;
                break;
            }
        }

        if (areEqual) {
            return true;
        }

    }

    return false;
}

int main()
{
    size_t firstSize, secondSize;
    std::cin >> firstSize >> secondSize;

    if (!isValidSize(firstSize) || !isValidSize(secondSize)) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int first[MAX_SIZE];
    int second[MAX_SIZE];

    readArr(first, firstSize);
    readArr(second, secondSize);

    std::cout << isSubarray(first, firstSize, second, secondSize);
}

