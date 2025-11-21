#include <iostream>

const size_t SIZE = 20;
const size_t RANGE = 20;

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printOccurrences(const int arr[], size_t size) {
    int count[RANGE]{ 0 };

    for (size_t i = 0; i < size; i++) {
        if (arr[i] >= 0 && arr[i] < RANGE) {
            count[arr[i]]++;
        }
    }

    for (size_t i = 0; i < RANGE; i++) {
        std::cout << i << " -> " << count[i] << '\n';
    }
}

int main()
{
    int arr[SIZE];

    readArr(arr, SIZE);
    printOccurrences(arr, SIZE);

    return 0;
}