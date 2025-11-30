#include <iostream>
const size_t MAX_SIZE = 1024;

int main()
{
    int n;
    std::cin >> n;

    int arr[MAX_SIZE];

    // Read elements
    for (int i = 0; i < n; i++) {
        std::cin >> *(arr + i);
    }

    // Print elements
    for (int i = 0; i < n; i++) {
        std::cout << *(arr + i) << " ";
    }

    return 0;
}

