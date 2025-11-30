#include <iostream>
const size_t MAX_LEN = 1024;

size_t myStrLen(const char* str) {
	if (!str) {
		return 0;
	}

	size_t index = 0;
	while (str[index]) {
		index++;
	}

	return index;
}

void myStrCpy(char* destination, const char* source) {
	if (!destination || !source) {
		return;
	}

	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';
}

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

void replaceWithBuffer(const char* text, const char* where, const char* what, char* result) {
	if (!text || !where || !what || !result) {
		return;
	}

	if (where[0] == '\0') {
		return;
	}

	size_t whereLen = myStrLen(where);
	size_t whatLen = myStrLen(what);

	while (*text) {
		if (isPrefix(text, where)) {
			myStrCpy(result, what);
			result += whatLen;
			text += whereLen;
		}
		else {
			*result = *text;
			result++;
			text++;
		}
	}

	*result = '\0';
}

void shiftRight(char* text, size_t positions) {
	int len = myStrLen(text);

	for (int i = len; i >= 0; i--) {
		text[i + positions] = text[i];
	}
}

void shiftLeft(char* text, size_t startIndex, size_t destinationIndex) {
	int tailLen = myStrLen(text + startIndex);

	for (int i = 0; i <= tailLen; i++) {
		text[destinationIndex + i] = text[startIndex + i];
	}
}

void replaceInPlace(char* text, const char* where, const char* what) {
	if (!text || !where || !what) {
		return;
	}

	if (where[0] == '\0') {
		return;
	}

	size_t whereLen = myStrLen(where);
	size_t whatLen = myStrLen(what);

	while (*text) {
		if (isPrefix(text, where)) {
			if (whatLen < whereLen) {
				for (size_t i = 0; i < whatLen; ++i) {
					text[i] = what[i];
				}

				shiftLeft(text, whereLen, whatLen);
			}
			else if (whatLen > whereLen) {
				size_t diff = whatLen - whereLen;

				if (myStrLen(text) + diff >= MAX_LEN) {
					return;
				}

				shiftRight(text, diff);

				for (size_t i = 0; i < whatLen; ++i) {
					text[i] = what[i];
				}
			}
			else {
				for (size_t i = 0; i < whatLen; ++i) {
					text[i] = what[i];
				}
			}

			text += whatLen;
		}
		else {
			text++;
		}
	}
}

int main()
{
	char text[MAX_LEN] = "I am the best of the best";
	const char* where = "best";
	const char* what = "worst";

	replaceInPlace(text, where, what);
	std::cout << text << std::endl;

	const char* str = "I am the best of the best";
	char result[MAX_LEN];
	replaceWithBuffer(str, where, what, result);
	std::cout << result << std::endl;
}
