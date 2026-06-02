#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

// Function to partition the array on the basis of pivot
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

/*
// Example Usage:
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    std::cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    std::vector<int> arr2 = {4, 2, 1, 3};
    int n2 = arr2.size();
    std::cout << "Original array 2: ";
    printArray(arr2);

    quickSort(arr2, 0, n2 - 1);

    std::cout << "Sorted array 2: ";
    printArray(arr2);

    return 0;
}
*/
