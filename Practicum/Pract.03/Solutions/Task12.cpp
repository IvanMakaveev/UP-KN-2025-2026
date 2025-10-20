#include <iostream>

int main()
{
	int start, end;
	std::cin >> start >> end;

	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}

	for (int i = start; i <= end; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
				if (sum > i)
				{
					break;
				}
			}
		}

		if (sum == i)
		{
			std::cout << i << std::endl;
		}
	}
}