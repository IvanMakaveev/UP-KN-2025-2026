#include <iostream>

void swap(int& first, int& second) {
    first ^= second;
    second ^= first;
    first ^= second;
}

/*
Example of how the XOR swap works (first = 5, second = 3):

Step 0 (input):
first  = 5  -> 0101
second = 3  -> 0011

Step 1: first ^= second
first  = 0101 ^ 0011 = 0110 (6)
second = 0011

Step 2: second ^= first
second = 0011 ^ 0110 = 0101 (5)
first  = 0110

Step 3: first ^= second
first  = 0110 ^ 0101 = 0011 (3)
second = 0101 (5)

Result:
first  = 3
second = 5
*/

int main()
{
    int first, second;
    std::cin >> first >> second;

    swap(first, second);
    std::cout << first << " " << second << std::endl;
}
