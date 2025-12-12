#include <iostream>

unsigned int flipBit(unsigned int n, unsigned int pos) {
    unsigned int mask = 1 << pos;
    return n ^ mask;  
}

unsigned int setBit(unsigned int n, unsigned int pos, bool value) {
    int mask = 1 << pos;

    if (value) {
        n |= mask;   // set bit to 1
    }
    else {
        n &= ~mask;  // set bit to 0
    }

    return n;
}

int main() {
    unsigned int N, M;
    std::cin >> N >> M;

    unsigned int result = flipBit(N, M);
    std::cout << result;

    return 0;
}

/*
        Example:

        Input: 5 0
        N = 5 = 101 (binary)
        M = 0 (we flip the 0-th bit, the rightmost bit)

        Step 1: Create mask
            mask = 1 << 0 = 1 = 001 (binary)

        Step 2: XOR N with mask
            101
          ^ 001
          -----
            100

        Result: 4
    */