#include <iostream>

constexpr size_t MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void printDiagonals(const int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < n; i++) {
        std::cout << matrix[i][n - 1 - i] << " ";
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
    printDiagonals(matrix, n);

    return 0;
}
