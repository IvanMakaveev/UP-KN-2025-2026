#include <iostream>
#include <cmath>

const size_t MAX_SIZE = 1000;

double absValue(double num) {
    return num > 0 ? num : -num;
}

void readArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
}

void findAverageAndClosest(const int arr[], size_t size, double& average, int& closest) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }

    average = sum*1.0 / size;

    closest = arr[0];
    double minDiff = absValue(arr[0] - average);

    for (size_t i = 1; i < size; i++) {
        double diff = absValue(arr[i] - average);

        if (diff < minDiff) {
            minDiff = diff;
            closest = arr[i];
        }
    }
}

int main()
{
    size_t size;
    std::cin >> size;

    if (size == 0 || size > MAX_SIZE) {
        std::cout << "Invalid input"<<std::endl;
        return 0;
    }

    int arr[MAX_SIZE];
    readArr(arr, size);

    double average = 0;
    int closest = 0;

    findAverageAndClosest(arr, size, average, closest);

    std::cout << average << " " << closest << std::endl;

    return 0;
}