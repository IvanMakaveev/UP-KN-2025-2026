#include <iostream>

void swap(int*& first, int*& second) {
    int* temp = first;
    first = second;
    second = temp;
}

int main() {
    int a, b;
    std::cin >> a >> b;

    int* ptr1 = &a;
    int* ptr2 = &b;

    swap(ptr1, ptr2);

    std::cout << *ptr1 << " " << *ptr2;
}
