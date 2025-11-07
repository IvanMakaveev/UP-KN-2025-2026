#include <iostream>

const size_t MAX_SIZE = 1000;

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

size_t longestEqualSequence(const int arr[], size_t size) {
    if (size == 0) {
        return 0;
    }

    size_t maxLen = 1;
    size_t currLen = 1;

    for (size_t i = 1; i < size; i++) {
        // If the current element is the same as the previous one, continue the sequence
        if (arr[i] == arr[i - 1]) {
            currLen++;
        }
        else {
            // Sequence breaks — update max length if needed
            if (currLen > maxLen) {
                maxLen = currLen;
            }
            currLen = 1; // reset for a new sequence
        }
    }

    // Check at the end in case the longest sequence ends at the last element
    if (currLen > maxLen) {
        maxLen = currLen;
    }

    return maxLen;
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

    size_t result = longestEqualSequence(arr, size);

    std::cout << result;

    return 0;
}