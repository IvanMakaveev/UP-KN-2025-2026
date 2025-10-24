#include <iostream>

double calculate(int a, int b, char action) {
	switch (action)
	{
	case '+': return a + b;

	case '-': return a - b;

	case '*': return a * b;

	case '/':
		if (b == 0) {
			return 0; //cannot be divided by zero
		}

		return (double)a / b;

	case '%':
		if (b == 0) {
			return -1; //cannot be divided by zero
		}

		return a % b;

	default:
		return a + b;
	}
}

int main()
{
	std::cout << calculate(10, 5, '+') << std::endl;
	std::cout << calculate(9, 2, '/') << std::endl;
	std::cout << calculate(5, 0, '%')<<std::endl;
}

