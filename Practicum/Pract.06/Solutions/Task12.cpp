#include <iostream>

const size_t MAX_SIZE = 1000;

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
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

void zigZagSort(int arr[], size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        if (i % 2 == 0) {
            // For even positions (0, 2, 4, ...), we want arr[i] > arr[i+1]
            if (arr[i] <= arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        else {
            // For odd positions (1, 3, 5, ...), we want arr[i] < arr[i+1]
            if (arr[i] >= arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int main() {
    size_t size;
    std::cin >> size;

    if (size == 0 || size > MAX_SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int arr[MAX_SIZE];
    readArr(arr, size);

    zigZagSort(arr, size);
    printArr(arr, size);

    return 0;
}