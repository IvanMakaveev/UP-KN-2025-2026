#include <iostream>

void partitionByIndex(int*& arr, size_t size, size_t index) {
    if (!arr || index >= size) {
        return;
    }

    int pivot = arr[index];
    int* result = new int[size];
    size_t pos = 0;

    // Elements smaller than pivot
    for (size_t i = 0; i < size; i++) {
        if (arr[i] < pivot) {
            result[pos++] = arr[i];
        }
    }

    // Elements equal to the pivot
    for (size_t i = 0; i < size; i++) {
        if (arr[i] == pivot) {
            result[pos++] = arr[i];
        }
    }

    // Elements greater than pivot
    for (size_t i = 0; i < size; i++) {
        if (arr[i] > pivot) {
            result[pos++] = arr[i];
        }
    }

    delete[] arr;
    arr = result;
}

// The relative order of the elements is NOT preserved.
// All elements smaller than or equal to the pivot are placed before it,
// and all elements greater than the pivot are placed after it.
void partitionByIndex2(int*& arr, size_t size, size_t index) {
    if (!arr || index >= size) {
        return;
    }

    int pivot = arr[index];

    int* result = new int[size];
    int left = 0;
    int right = size - 1;

    for (int i = 0; i < size; i++) {
        if (i != index && arr[i] <= pivot) {
            result[left++] = arr[i];
        }
        else if (arr[i] > pivot) {
            result[right--] = arr[i];
        }
    }

    result[left] = pivot;
    delete[] arr;
    arr = result;
}

void readArray(int* arr, size_t size) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void printArray(const int* arr, size_t size) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    size_t size, index;
    std::cin >> size >> index;

    int* arr = new int[size];
    readArray(arr, size);

    partitionByIndex(arr, size, index);

    printArray(arr, size);

    delete[] arr;
}