#include <iostream>

bool isBinaryNum(unsigned int number) {
	while (number) {
		int lastDigit = number % 10;

		if (lastDigit != 0 && lastDigit != 1) {
			return false;
		}

		number /= 10;
	}

	return true;
}

int getSwapsCount(unsigned int first, unsigned int second) {
	if (!isBinaryNum(first) || !isBinaryNum(second)) {
		return -1;
	}

	int swap01 = 0; // Count of 0 -> 1 swaps needed
	int swap10 = 0; // Count of 1 -> 0 swaps needed

	while (first && second) {
		int firstLast = first % 10;
		first /= 10;
		int secondLast = second % 10;
		second /= 10;

		if (firstLast == secondLast) {
			continue; // No swap needed if digits are the same
		}
		else if (firstLast == 1) {
			swap10++; // 1 in first number needs to become 0
		}
		else {
			swap01++; // 0 in first number needs to become 1
		}
	}

	// If first number has remaining digits
	while (first) {
		int last = first % 10;
		first /= 10;

		if (last == 1) {
			swap10++;
		}
	}

	// If second number has remaining digits
	while (second) {
		int last = second % 10;
		second /= 10;

		if (last == 1) {
			swap01++;
		}
	}

	// If the number of 0->1 swaps is different from 1->0 swaps, it's impossible
	if (swap01 != swap10) {
		return -1;
	}

	return swap01;
}

int main()
{
	unsigned int first, second;
	std::cin >> first >> second;

	int swaps = getSwapsCount(first, second);

	std::cout << swaps << std::endl;
}

