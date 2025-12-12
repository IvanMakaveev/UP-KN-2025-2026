#include <iostream>

bool getBit(unsigned int n,unsigned int pos) {
    int mask = 1 << pos; //mask with 1 at the desired position

    return mask & n;
}


int main()
{
    unsigned int N, M;
    std::cin >> N >> M;

    std::cout << getBit(N, M);
}

