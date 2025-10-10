#include <iostream>

int main()
{
	char c;
	std::cin >> c;

	if (c >= 'a' && c <= 'z') {
		char uppercaseLetter = c - 'a' + 'A';
		std::cout <<  uppercaseLetter;
	}
	else if (c >= 'A' && c <= 'Z') {
		char lowercaseLetter = c - 'A' + 'a';
		std::cout << lowercaseLetter;
	}
	else {
		std::cout << "Invalid character";
	}
}
