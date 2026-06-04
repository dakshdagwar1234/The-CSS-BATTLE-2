#include <iostream>
#include <vector>
#include <algorithm>

void efficientSort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    efficientSort(arr);

    std::cout << "Sorted array (using std::sort for efficiency): ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
