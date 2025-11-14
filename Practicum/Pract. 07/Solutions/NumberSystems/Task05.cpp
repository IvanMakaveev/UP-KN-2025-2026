#include <iostream>
constexpr size_t SIZE = 32;

void printArray(const bool arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i];
    }

    std::cout << std::endl;
}

void printBinary32(unsigned int number) {
    bool binary[SIZE]{ 0 };

    // Fill array from right to left
    for (int i = SIZE - 1; i >= 0; i--) {
        binary[i] = number % 2;
        number /= 2;

        if (number == 0) {
            break;
        }
    }

    printArray(binary, SIZE);
}

int main() {
    unsigned int num = 10;
    printBinary32(num); // Output: 00000000000000000000000000001010
    return 0;
}
