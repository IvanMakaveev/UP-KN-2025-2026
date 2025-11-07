#include <iostream>
const size_t MAX_SIZE = 1000;

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

int firstRepeated(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    size_t size;
    std::cin >> size;

    if (size<1 ||size > MAX_SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 0;
    }

    int arr[MAX_SIZE];
    readArr(arr, size);

    std::cout << firstRepeated(arr, size);
}
