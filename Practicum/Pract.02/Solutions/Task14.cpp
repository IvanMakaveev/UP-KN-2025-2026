#include <iostream>

int main()
{
	int radius = 0, x = 0, y = 0;
	std::cin >> radius >> x >> y;

	int distanceFromCentreSquared = x * x + y * y;
	int radiusSquared = radius * radius;

	if (distanceFromCentreSquared < radiusSquared)
	{
		std::cout << "In the circle";
	}
	else if (distanceFromCentreSquared > radiusSquared)
	{
		std::cout << "Out of the circle";
	}
	else
	{
		std::cout << "On the circle";
	}
}