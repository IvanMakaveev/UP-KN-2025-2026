#include <iostream>
const size_t MAX_SIZE = 1024;
const size_t SYMBOLS_COUNT = 256;

size_t strLen(const char* str) {
	if (!str) {
		return 0;
	}

	size_t length = 0;

	while (*str) {
		length++;
		str++;
	}

	return length;
}

bool areAnagrams(const char* str1, const char* str2) {
	if (!str1 || !str2) {
		return false;
	}

	size_t firstLength = strLen(str1);
	size_t secondLength = strLen(str2);

	if (firstLength != secondLength) {
		return false;
	}

	int count[SYMBOLS_COUNT]{ 0 };

	while (*str1) {
		count[*str1]++;
		str1++;
	}

	while (*str2) {
		if (count[*str2] == 0) {
			return false;
		}

		count[*str2]--;
		str2++;
	}

	return true;
}

int main()
{
	const char* str1 =  "listen";
	const char* str2 = "silent";

	std::cout << areAnagrams(str1, str2);
}

