#include <iostream>

int main()
{
	while (true) {
		int number;
		std::cin >> number;

		int numCopy = number;
		int digitsSum = 0;

		while (number != 0) {
			digitsSum += (number % 10);
			number /= 10;
		}

		int total = digitsSum + numCopy;

		if (total % 10 == 0) {
			std::cout << "End of program [" << numCopy << " + " << digitsSum << " = " << total << " is divisible by 10]" <<std::endl;
			break;
		}
		else {
			std::cout << "Bad number [" << numCopy << " + " << digitsSum << " = " << total << " is not divisible by 10]" << std::endl;
		}
	}
}

