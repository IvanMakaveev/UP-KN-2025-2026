#include <iostream>

const size_t MAX_SIZE = 1024;
const size_t MAX_DIGITS_COUNT = 12;

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

void countDigits(const char* str, char* result) {
    if (!str || !result) {
        result[0] = '\0';
        return;
    }

    int counts[10] = { 0 };

    while (*str) {
        if (!isDigit(*str)) {
            result[0] = '\0';
            return; //invalid input
        }

        counts[*str - '0']++;
        str++;
    }

    bool first = true;

    for (int digit = 0; digit < 10; digit++) {
        if (counts[digit] > 0) {
            if (!first) {
                *result = ','; 
                result++;
            }

            int count = counts[digit];
             
            //use additional array because the number of 
            // occurrences may be a multi-digit number
            char temp[MAX_DIGITS_COUNT];
            int idx = 0;
            
            do {
                temp[idx++] = '0' + (count % 10);
                count /= 10;
            } while (count > 0);

            for (int i = idx - 1; i >= 0; i--) {
                *result = temp[i];
                result++;
            }

            *result = 'x';
            result++;

            *result = '0' + digit;
            result++;

            first = false;
        }
    }

    *result = '\0';

}
int main()
{
    char str[MAX_SIZE];
    char result[MAX_SIZE];
    std::cin >> str;

    countDigits(str, result);
    std::cout << result;
}
