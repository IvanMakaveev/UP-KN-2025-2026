#include <iostream>

unsigned int getLastKBits(unsigned int n, unsigned int k) {
    if (k == 0) {
        return 0;
    }

    unsigned int mask = (1 << k) - 1;  // mask with last k bits set to 1
    return n & mask;            
}

int main() {
    unsigned int n, k;
    std::cin >> n >> k;

    std::cout << getLastKBits(n, k);

    return 0;
}
