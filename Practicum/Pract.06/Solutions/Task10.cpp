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

void merge(const int first[], size_t firstSize, const int second[], size_t secondSize, int result[], size_t& resultSize) {
    resultSize = 0;
    size_t firstIndex = 0;
    size_t secondIndex = 0;

    while (firstIndex < firstSize && secondIndex < secondSize) {
        if (first[firstIndex] <= second[secondIndex]) {
            result[resultSize++] = first[firstIndex++];
        }
        else {
            result[resultSize++] = second[secondIndex++];
        }
    }

    while (firstIndex < firstSize) {
        result[resultSize++] = first[firstIndex++];
    }

    while (secondIndex < secondSize) {
        result[resultSize++] = second[secondIndex++];
    }
}

int main()
{
    size_t firstSize, secondSize;
    std::cin >> firstSize >> secondSize;

    if (!isValidSize(firstSize) || !isValidSize(secondSize) || (firstSize + secondSize >= MAX_SIZE)) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int first[MAX_SIZE];
    int second[MAX_SIZE];

    readArr(first, firstSize);
    readArr(second, secondSize);

    int result[MAX_SIZE];
    size_t resultSize = 0;

    merge(first, firstSize, second, secondSize, result, resultSize);
    printArr(result, resultSize);
}
