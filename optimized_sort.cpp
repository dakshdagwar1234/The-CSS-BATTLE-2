#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

// Function to perform optimized sorting using std::sort
// std::sort typically uses IntroSort, which is a hybrid sorting algorithm
// with an average time complexity of O(N log N) and a worst-case of O(N log N).
// Space Complexity: O(log N) for recursion stack (IntroSort) or O(N) for some implementations.
void optimizedSort(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Function to print a vector
void printVector(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test cases
    std::vector<std::vector<int>> test_arrays = {
        {},                          // Empty array
        {1},                         // Single element
        {64, 25, 12, 22, 11},        // General case
        {5, 5, 5, 5, 5},             // All same elements
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, // Reverse sorted
        {-5, 0, 5, -10, 10},         // Negative and zero
        {1, 2, 3, 4, 5}              // Already sorted
    };

    for (size_t i = 0; i < test_arrays.size(); ++i) {
        std::cout << "Original array " << i + 1 << ": ";
        printVector(test_arrays[i]);

        optimizedSort(test_arrays[i]);

        std::cout << "Sorted array " << i + 1 << ": ";
        printVector(test_arrays[i]);
        std::cout << "------------------------------" << std::endl;
    }

    return 0;
}
