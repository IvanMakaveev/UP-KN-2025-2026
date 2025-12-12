#include <iostream>

int countOnes(unsigned x) {
    int count = 0;

    while (x) {
        count += x & 1;
        x >>= 1;
    }

    return count;
}

bool isBitPermutation(unsigned a, unsigned b) {
    int countOnesInA = countOnes(a);
    int countOnesInB = countOnes(b);

    return countOnesInA == countOnesInB;
}

int main() {
    unsigned a, b;
    std::cin >> a >> b;

    std::cout << isBitPermutation(a, b);

    return 0;
}


