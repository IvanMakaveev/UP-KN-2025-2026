#include <iostream>
#include <climits>

constexpr size_t MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

int getMinElement(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
    int minEl = INT_MAX;

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (matrix[i][j] < minEl) {
                minEl = matrix[i][j];
            }
        }
    }

    return minEl;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t rows, cols;
    std::cin >> rows >> cols;

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        std::cout << "Invalid size";
        return 0;
    }

    readMatrix(matrix, rows, cols);
    std::cout << getMinElement(matrix, rows, cols);
}
