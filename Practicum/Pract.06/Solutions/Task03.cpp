#include <iostream>

const size_t SIZE = 20;

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int findMissing(const int arr[], size_t size) {
    int totalSum = (size * (size + 1)) / 2; // sum of 0..20
    int arrSum = 0;

    for (size_t i = 0; i < size; i++) {
        arrSum += arr[i];
    }

    return totalSum - arrSum; // missing number
}

int main()
{
    int arr[SIZE];
    readArr(arr, SIZE);

    std::cout << findMissing(arr, SIZE);
}
