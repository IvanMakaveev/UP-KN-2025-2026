#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int first = 0;
	int second = 1;

	while (n != 0) {
		std::cout << first << " ";
		int temp = first;
		first = second;
		second += temp;
		n--;
	}
}

