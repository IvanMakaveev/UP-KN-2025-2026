#include <iostream>

bool isPalindrome(const int* arr, size_t startIndex, size_t endIndex) {
    if (!arr) {
        return false;
    }

    size_t midIndex = startIndex + (endIndex - startIndex) / 2;

    for (size_t i = startIndex; i <= midIndex; i++) {
        if (arr[i] != arr[endIndex - (i - startIndex)]) {
            return false;
        }
    }

    return true;
}

bool isConcatenationOfPalindromes(const int* arr, size_t size) {
    if (!arr) {
        return false;
    }

    for (size_t i = 1; i < size - 1; i++) {
        if (isPalindrome(arr, 0, i) && isPalindrome(arr, i + 1, size - 1)) {
            return true;
        }
    }

    return false;
}

//Another solution: 

bool isPalindrome(const int* arr, size_t size) {
    if (!arr) {
        return false;
    }

    for (size_t i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool isConcatenationOfPalindromes2(const int* arr, size_t size) {
    if (!arr) {
        return false;
    }

    for (size_t i = 1; i < size; i++) {
        if (isPalindrome(arr, i) && isPalindrome(arr + i, size - i)) {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[] = { 3,6,4,6,3,1,2,1 };
    std::cout << isConcatenationOfPalindromes(arr, 8) << std::endl;
    std::cout << isConcatenationOfPalindromes2(arr, 8) << std::endl;
    
    int arr2[] = { 7,8,5,6 };
    std::cout << isConcatenationOfPalindromes(arr2, 4) << std::endl;
    std::cout << isConcatenationOfPalindromes2(arr2, 4) << std::endl;
}
