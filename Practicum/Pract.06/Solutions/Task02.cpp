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

    std::cout << '\n';
}

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void reverseFirstK(int arr[], size_t size, size_t K) {
    if (K > size) {
        return;
    }

    for (size_t i = 0; i < K / 2; i++) {
        swap(arr[i], arr[K - 1 - i]);
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

    size_t K;
    std::cin >> K;

    reverseFirstK(arr, size, K);
    printArr(arr, size);
}