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

void printArr(const int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

bool doesContain(const int arr[], size_t size, int element) {
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == element) {
            return true;
        }
    }

    return false;
}

void getUnion(const int first[], size_t firstSize, const int second[], size_t secondSize, int result[], size_t& resultSize) {
    for (size_t i = 0; i < firstSize; i++) {
        bool isInResult = doesContain(result, resultSize, first[i]);

        if (!isInResult) {
            result[resultSize++] = first[i];
        }
    }

    for (size_t i = 0; i < secondSize; i++) {
        bool isInResult = doesContain(result, resultSize, second[i]);

        if (!isInResult) {
            result[resultSize++] = second[i];
        }
    }
}

void getIntersection(const int first[], size_t firstSize, const int second[], size_t secondSize, int result[], size_t& resultSize) {
    for (size_t i = 0; i < firstSize; i++) {
        bool isInSecond = doesContain(second, secondSize, first[i]);

        if (!isInSecond) {
            continue;
        }

        bool isInResult = doesContain(result, resultSize, first[i]);

        if (isInSecond && !isInResult) {
            result[resultSize++] = first[i];
        }
    }
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

    size_t unionSize = 0;
    size_t intersectionSize = 0;

    int intersectionArray[MAX_SIZE];
    int unionArray[MAX_SIZE];

    getUnion(first, firstSize, second, secondSize, unionArray, unionSize);
    getIntersection(first, firstSize, second, secondSize, intersectionArray, intersectionSize);

    std::cout << "Union: ";
    printArr(unionArray, unionSize);

    std::cout << "Intersection: ";
    printArr(intersectionArray, intersectionSize);
}

