#include <iostream>

void readArr(int* arr,size_t len) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < len; i++) {
        std::cin >> arr[i];
    }
}

void insertAt(int*& arr, size_t& len, size_t index, int elem) {
    if (!arr) {
        return;
    }

    if (index > len) {
        return;
    }

    len++;
    int* result = new int[len];
    int currentIndex = 0;
    int oldArrIndex = 0;
    for (size_t i = 0; i < len; i++) {
        if (index == i) {
            result[currentIndex++] = elem;
        }
        else {
            result[currentIndex++] = arr[oldArrIndex++];
        }
    }

    delete[] arr;
    arr = result;
}

void removeAt(int*& arr, size_t& len, size_t index) {
    if (!arr) {
        return;
    }

    if (index >= len) {
        return;
    }

    len--;
    int* result = new int[len];

    int resultIndex = 0;
    int oldIndex = 0;
    for (size_t i = 0; i < len + 1; i++) {
        if (index == i) {
            oldIndex++;
        }
        else {
            result[resultIndex++] = arr[oldIndex++];
        }
    }

    delete[] arr;
    arr = result;
}

void printArr(const int* arr, size_t len) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    size_t len;
    std::cin >> len;
    int* arr = new int[len];
    readArr(arr, len);

    //size_t index, numToInsert;
    //std::cin >> index >> numToInsert;
    //insertAt(arr, len, index, numToInsert);
 
    size_t index;
    std::cin >> index;

    removeAt(arr, len, index);
    printArr(arr, len);

    delete[] arr;
}