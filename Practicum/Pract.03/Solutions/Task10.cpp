#include <iostream>

int main()
{
	unsigned int N;
	std::cin >> N;

	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			sum += j;
		}
	}

	std::cout << sum;
}
