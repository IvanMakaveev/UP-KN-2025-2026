#include <iostream>

int main()
{
	const char CONVERT_FROM_UPPER_TO_LOWER = 'a' - 'A';

	// Think about adding validation to the input parameters
	char capitalStart, capitalEnd, lowerStart, lowerEnd, currentSymbol;
	std::cin >> capitalStart >> capitalEnd >> lowerStart >> lowerEnd >> currentSymbol;

	if (currentSymbol >= 'A' && currentSymbol <= 'Z')
	{
		currentSymbol += CONVERT_FROM_UPPER_TO_LOWER;
	}

	capitalStart += CONVERT_FROM_UPPER_TO_LOWER;
	capitalEnd += CONVERT_FROM_UPPER_TO_LOWER;

	bool isInFirstSet = (currentSymbol >= capitalStart && currentSymbol <= capitalEnd);
	bool isInSecondSet = (currentSymbol >= lowerStart && currentSymbol <= lowerEnd);

	// Sub-task #1
	bool isInUnion = isInFirstSet || isInSecondSet;
	// Sub-task #2
	bool isInIntersection = isInFirstSet && isInSecondSet;
	// Sub-task #3
	bool isInDifference = isInFirstSet && !isInSecondSet;
	// Sub-task #4
	bool isInOnlyOneSet = isInUnion && !isInIntersection;

	std::cout << (isInUnion ? "true, " : "false, ");
	std::cout << (isInIntersection ? "true, " : "false, ");
	std::cout << (isInDifference ? "true, " : "false, ");
	std::cout << (isInOnlyOneSet ? "true, " : "false, ");
}