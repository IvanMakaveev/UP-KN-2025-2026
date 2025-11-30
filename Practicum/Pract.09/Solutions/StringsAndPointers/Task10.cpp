#include <iostream>

bool isPrefix(const char* text, const char* expectedPrefix) {
	if (!text || !expectedPrefix) {
		return false;
	}

	while (*expectedPrefix) {
		if (*text != *expectedPrefix) {
			return false;
		}
		text++;
		expectedPrefix++;
	}

	return true;
}

int numberOfOccurrences(const char* str, const char* searched) {
	if (!str || !searched) {
		return 0;
	}

	if (*searched == '\0') {
		return 0;
	}

	int count = 0;

	while (*str) {
		if (isPrefix(str, searched)) {
			count++;
		}

		str++;
	}

	return count;
}

int main()
{
	const char* str = "abcdabcabababc";
	const char* searched = "abc";

	std::cout << numberOfOccurrences(str, searched);
}
