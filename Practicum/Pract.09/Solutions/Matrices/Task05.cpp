#include <iostream>

constexpr size_t MAX_SIZE = 50;

void swap(int& first, int& second) {
    int temp = first;
    first = second;
    second = temp;
}

void readMatrix(int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void transposeMatrix(int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(const int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t n;
    std::cin >> n;

    if (n > MAX_SIZE) {
        std::cout << "Invalid size";
        return 0;
    }

    readMatrix(matrix, n);
    transposeMatrix(matrix, n);
    printMatrix(matrix, n);

    return 0;
}
