#include <iostream>

constexpr size_t MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void printZigZag(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        if (i % 2 == 0) { //even row
            for (size_t j = 0; j < cols; j++) {
                std::cout << matrix[i][j] << " ";
            }
        }
        else { //odd row
            for (int j = cols - 1; j >= 0; j--) {
                std::cout << matrix[i][j] << " ";
            }
        }

        std::cout << std::endl;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t rows, cols;
    std::cin >> rows >> cols;

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        std::cout << "Invalid input";
        return 0;
    }

    readMatrix(matrix, rows, cols);
    printZigZag(matrix, rows, cols);

    return 0;
}
