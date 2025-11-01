#include <iostream>

void validateStudent(int& age, int& facultyNumber) {
    if (age < 15 || age > 100) {
        age = 15;
    }

    if (facultyNumber < 10000 || facultyNumber > 99999) {
        facultyNumber = 10000;
    }
}

int main() {
    int age, fn;
    std::cin >> age >> fn;

    validateStudent(age, fn);

    std::cout << age << " " << fn << std::endl;

    return 0;
}

