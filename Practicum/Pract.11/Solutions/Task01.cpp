#include <iostream>

int* merge(const int* arr1, size_t size1, const int* arr2, size_t size2) {
	size_t resultSize = size1 + size2;
	int* result = new int[resultSize];

	size_t firstIndex = 0;
	size_t secondIndex = 0;
	size_t resultIndex = 0;

	while (firstIndex < size1 && secondIndex < size2) {
		if (arr1[firstIndex] < arr2[secondIndex]) {
			result[resultIndex++] = arr1[firstIndex++];
		}
		else {
			result[resultIndex++] = arr2[secondIndex++];
		}
	}

	while (firstIndex < size1) {
		result[resultIndex++] = arr1[firstIndex++];
	}

	while (secondIndex < size2) {
		result[resultIndex++] = arr2[secondIndex++];
	}

	return result;
}

void readArray(int* arr, size_t size) {
	if (!arr) {
		return;
	}

	for (size_t i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

void printArray(const int* arr, size_t size) {
	if (!arr) {
		return;
	}

	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

int main()
{
	size_t firstSize;
	std::cin >> firstSize;
	int* arr1 = new int[firstSize];
	readArray(arr1, firstSize);

	size_t secondSize;
	std::cin >> secondSize;
	int* arr2 = new int[secondSize];
	readArray(arr2, secondSize);

	int* result = merge(arr1, firstSize, arr2, secondSize);
	size_t resultSize = firstSize+ secondSize;

	printArray(result, resultSize);

	delete[] arr1;
	delete[] arr2;
	delete[] result;
}
