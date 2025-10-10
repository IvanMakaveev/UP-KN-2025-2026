#include <iostream>
using namespace std;

int main()
{
	double firstOperand = 0, secondOperand = 0;
	char operation = '\0';
	const double EPSILON = 1e-9;

	cin >> firstOperand >> operation >> secondOperand;

	switch (operation)
	{
	case '+':
		cout << firstOperand + secondOperand;
		break;

	case '-':
		cout << firstOperand - secondOperand;
		break;

	case '*':
		cout << firstOperand * secondOperand;
		break;

	case '/':
		if (std::abs(secondOperand) < EPSILON)
		{
			cout << "Cannot divide by 0";
			break;
		}

		cout << firstOperand / secondOperand;
		break;
	}
}