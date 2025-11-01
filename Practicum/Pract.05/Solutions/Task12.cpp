#include <iostream>

bool isLeapYear(unsigned year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

unsigned getDaysInMonth(unsigned month, unsigned year) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

bool isValidDate(unsigned day, unsigned month, unsigned year) {
    if (month < 1 || month > 12 || year == 0) {
        return false;
    }

    unsigned daysInMonth = getDaysInMonth(month, year);
    return day >= 1 && day <= daysInMonth;
}

void goToNextDay(unsigned& day, unsigned& month, unsigned& year) {
    day++;

    if (day > getDaysInMonth(month, year)) {
        day = 1;
        if (month < 12) {
            month++;
        }
        else {
            month = 1;
            year++;
        }
    }
}

void addDays(unsigned& day, unsigned& month, unsigned& year, unsigned daysToAdd) {
    for (unsigned i = 0; i < daysToAdd; i++) {
        goToNextDay(day, month, year);
    }
}

void printDate(unsigned day, unsigned month, unsigned year) {
    std::cout << (day < 10 ? "0" : "") << day << "."
        << (month < 10 ? "0" : "") << month << "."
        << year << std::endl;
}

int main()
{
    std::cout << "Enter date in format dd mm yyyy: " << std::endl;
    unsigned day, month, year;
    std::cin >> day >> month >> year;

    std::cout << "Enter days, which will be added: " << std::endl;
    unsigned daysToAdd;
    std::cin >> daysToAdd;

    if (!isValidDate(day, month, year)) {
        std::cout << "Invalid date" << std::endl;
        return 0;
    }

    addDays(day, month, year, daysToAdd);
    printDate(day, month, year);
}
