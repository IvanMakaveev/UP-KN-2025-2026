#include <iostream>

int main() {
    int inputSeconds;

    std::cout << "Seconds: ";
    std::cin >> inputSeconds;

    int days = inputSeconds / (60 * 60 * 24);
    int hours = (inputSeconds / (60 * 60)) % 24;
    int minutes = (inputSeconds / 60) % 60;
    int seconds = inputSeconds % 60;

    std::cout << days << " days, "
        << hours << " hours, "
        << minutes << " minutes and "
        << seconds << " seconds";
}