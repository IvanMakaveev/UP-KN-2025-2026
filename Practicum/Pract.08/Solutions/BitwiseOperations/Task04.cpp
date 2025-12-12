#include <iostream>

bool containsBinary(unsigned int n, unsigned int k) {
    if (k == 0) {
        return true; // 0 appears everywhere
    }

    // Count how many bits are in k
    unsigned int kBits = 0;
    unsigned int tmp = k;
    while (tmp > 0) {
        kBits++;
        tmp >>= 1;
    }

    // Slide a window of length kBits over n
    unsigned int mask = (1 << kBits) - 1; // mask of length kBits
    unsigned int nBits = 0;
    tmp = n;

    // Count bits in n
    while (tmp > 0) {
        nBits++;
        tmp >>= 1;
    }

    if (kBits > nBits) {
        return false; // k is longer than n -  cannot appear
    }

    // Slide over all possible positions
    for (unsigned int i = 0; i <= nBits - kBits; i++) {
        if (((n >> i) & mask) == k) {
            return true;
        }
    }

    return false;
}

int main() {
    unsigned int n, k;
    std::cin >> n >> k;

    std::cout << (containsBinary(n, k));
      
    return 0;
}
