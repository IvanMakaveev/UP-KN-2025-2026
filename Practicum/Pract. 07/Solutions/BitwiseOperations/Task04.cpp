#include <iostream>

int absBitwise(int number) {
    int mask = number < 0;
   // If mask = 0 → (number ^ 0) + 0 = number
   // If mask = 1 → (number ^ -1) + 1 = -number
    return (number ^ -mask) + mask;
}

/*
      Example with number = -5 (using 8-bit binary for clarity):

      number = -5 → binary: 11111011
      mask   = 1
      -mask  = -1 → binary: 11111111

      Step 1: number ^ -mask
              11111011  (-5)
            ^ 11111111  (-1)
            = 00000100  (4)

      Step 2: + mask
              00000100
            + 00000001
            = 00000101  (5)

      Result: absBitwise(-5) = 5
   */

int main()
{
    int number;
    std::cin >> number;

    std::cout << absBitwise(number);
}
