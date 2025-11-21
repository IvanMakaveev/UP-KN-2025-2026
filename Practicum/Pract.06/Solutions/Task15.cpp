#include <iostream>
const int MAX_SIZE = 100;

void readArr(int arr[], int size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int BinarySearch(const int arr[], int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == 0) {
            return mid;
        }
        else if (arr[mid] % 2 == 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int size;
    std::cin >> size;

    if (size == 0 || size > MAX_SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int arr[MAX_SIZE];
    readArr(arr, size);

    std::cout << BinarySearch(arr, size);
}
