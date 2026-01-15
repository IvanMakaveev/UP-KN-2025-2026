#include <iostream>

// Allocate a subarray and copy elements
int* copySubarray(const int* arr, size_t start, size_t end) {
    size_t len = end - start + 1;
    int* sub = new int[len];
    for (size_t i = 0; i < len; i++) {
        sub[i] = arr[start + i];
    }
    return sub;
}

void generateSubarrays(const int* arr, size_t size, int**& result, size_t*& lengths, size_t& subarrayCount) {
    if (!arr) {
        subarrayCount = 0;
        lengths = nullptr;
        result = nullptr;
        return;
    }

    // Count total number of subarrays = n*(n+1)/2
    subarrayCount = size * (size + 1) / 2;

    result = new int* [subarrayCount];   // array of pointers to subarrays
    lengths = new size_t[subarrayCount]; // store lengths of each subarray

    size_t index = 0;

    // For each start index, iterate through all possible end indices >= start
    // Copy the subarray arr[start..end] into the result array and store its length
    for (size_t start = 0; start < size; start++) {
        for (size_t end = start; end < size; end++) {
            result[index] = copySubarray(arr, start, end);
            lengths[index] = end - start + 1;
            index++;
        }
    }
}

void freeMatrix(int** matrix, size_t* lengths, size_t count) {
    for (size_t i = 0; i < count; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
    delete[] lengths;
}

void printSubarrays(int** matrix, size_t* lengths, size_t count) {
    if (!matrix || !lengths) {
        return;
    }

    for (size_t i = 0; i < count; i++) {
        std::cout << "[ ";
        for (size_t j = 0; j < lengths[i]; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }
}

void readArr(int* arr, size_t size) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int main() {
    size_t size;
    std::cin >> size;

    int* arr = new int[size];
    readArr(arr, size);

    int** subarrays;
    size_t* lengths;
    size_t count;

    generateSubarrays(arr, size, subarrays, lengths, count);

    printSubarrays(subarrays, lengths, count);

    freeMatrix(subarrays, lengths, count);

    delete[] arr;
    return 0;
}
