#include <iostream>

constexpr size_t MAX_SIZE = 50;

void readMatrix(int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

bool isUpperTriangular(const int matrix[][MAX_SIZE], size_t n) {
    for (size_t i = 1; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
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

    std::cout << isUpperTriangular(matrix, n) << std::endl;

    return 0;
}
