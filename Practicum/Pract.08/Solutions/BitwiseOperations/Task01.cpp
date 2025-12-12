#include <iostream>

unsigned powerOf2(unsigned k) {
    if (k > 31) {
        return -1;
    }

    return 1 << k;
}

int main()
{
    unsigned k;
    std::cin >> k;
    std::cout<<powerOf2(k);
}

