#include <iostream>

int main()
{
    int sum = 0;

    for (int i = 100; i <= 999; i++) {
        int numCopy = i;
        int digitsSum = 0;

        while (numCopy != 0) {
            int lastDigit = numCopy % 10;
            numCopy /= 10;
            digitsSum += lastDigit;
        }

        if (digitsSum < 10) {
            continue;
        }

        double sqrt = std::sqrt(digitsSum);
        bool isPrime = true;

        for (int j = 2; j <= sqrt; j++) {
            if (digitsSum % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}
