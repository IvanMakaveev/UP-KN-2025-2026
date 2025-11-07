#include <iostream>
const size_t MAX_SIZE = 1000;

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

void numsInInterval(const int arr[], size_t arrSize, int result[], size_t& resultSize, int a, int b) {
    resultSize = 0;

    for (size_t i = 0; i < arrSize; i++) {
        if (a <= arr[i] && arr[i] <= b) {
            result[resultSize++] = arr[i];
        }
    }
}

int main()
{
    size_t size;
    std::cin >> size;

    if (size == 0 || size > MAX_SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int arr[MAX_SIZE];
    readArr(arr, size);

    int a, b;
    std::cin >> a >> b;

    size_t resultSize = 0;
    int result[MAX_SIZE];

    numsInInterval(arr, size, result, resultSize, a, b);
    printArr(result, resultSize);
}

