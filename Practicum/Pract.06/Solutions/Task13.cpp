#include <iostream>

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

void addOne(int arr[], size_t size) {
	bool addOne = true;

	for (int i = size - 1; i >= 0; i--) {
		int current = arr[i] + addOne;
		addOne = current >= 10;
		current %= 10;
		arr[i] = current;
	}
}

int main()
{
	constexpr size_t SIZE = 5;
	int arr[SIZE];
	readArr(arr, SIZE);
	addOne(arr, SIZE);
	printArr(arr, SIZE);
}

