#include <iostream>

int findNotDuplicated(const int arr[], size_t size) {
    int result = 0;

    // XOR all elements in the array
    for (unsigned i = 0; i < size; i++) {
        result ^= arr[i];
        // Each duplicate cancels out because x ^ x = 0
        // The non-duplicated number remains at the end
    }

    return result;
}

/*
Example with (arr = {2, 3, 5, 4, 5, 3, 2}):

Step 0: result = 0 -> 0000

Step 1: result ^= 2 -> 0 ^ 0010 = 0010
Step 2: result ^= 3 -> 0010 ^ 0011 = 0001
Step 3: result ^= 5 -> 0001 ^ 0101 = 0100
Step 4: result ^= 4 -> 0100 ^ 0100 = 0000
Step 5: result ^= 5 -> 0000 ^ 0101 = 0101
Step 6: result ^= 3 -> 0101 ^ 0011 = 0110
Step 7: result ^= 2 -> 0110 ^ 0010 = 0100

Result: 0100 (4) — the number that appears only once
*/

int main()
{
    const size_t SIZE = 7;
    int arr[SIZE] = { 2, 3, 5, 4, 5, 3, 2 };

    std::cout << findNotDuplicated(arr, SIZE);
}
