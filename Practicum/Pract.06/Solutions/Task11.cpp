#include <iostream>

const size_t MAX_SIZE = 1000;
const double EPSILON = 0.0000001;

double absValue(double num) {
	return num > 0 ? num : -num;
}

bool isValidSize(size_t size) {
	return size >= 0 && size <= MAX_SIZE;
}

void readArr(int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

void printArr(const int arr[], size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

bool areLinearlyDependent(const int first[], size_t firstSize, const int second[], size_t secondSize) {
	if (firstSize != secondSize) {
		return false;
	}
	else if (firstSize == 0) {
		return true;
	}

	double multi = 0;
	bool foundRatio = false;

	for (size_t i = 0; i < firstSize; i++) {
		if (absValue(second[i]) < EPSILON) {
			if (absValue(first[i]) > EPSILON) {
				return false; // one zero, one not
			}
			else {
				continue; // both zero, skip
			}
		}

		double currentMulti = first[i]*1.0 / second[i];

		if (!foundRatio) {
			multi = currentMulti;
			foundRatio = true;
		}
		else if (absValue(multi - currentMulti) > EPSILON) {
			return false;
		}
	}

	return true;
}

int main()
{
	size_t firstSize, secondSize;
	std::cin >> firstSize >> secondSize;

	if (!isValidSize(firstSize) || !isValidSize(secondSize)) {
		std::cout << "Invalid input" << std::endl;
		return 0;
	}

	int first[MAX_SIZE];
	int second[MAX_SIZE];

	readArr(first, firstSize);
	readArr(second, secondSize);

	std::cout << areLinearlyDependent(first, firstSize, second, secondSize);
}
