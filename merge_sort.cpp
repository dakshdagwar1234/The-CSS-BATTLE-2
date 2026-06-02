#include <iostream>
#include <vector>
#include <algorithm> // Required for std::copy

// Helper function to merge two sorted sub-arrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into arr[left..right]
    int i = 0; // Initial index of first sub-array
    int j = 0; // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main merge sort function
// @param arr: The vector of integers to be sorted.
// @param left: The starting index of the sub-array to be sorted.
// @param right: The ending index of the sub-array to be sorted.
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; // Base case: array with 0 or 1 element is already sorted
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);       // Sort first half
    mergeSort(arr, mid + 1, right);  // Sort second half
    merge(arr, left, mid, right);    // Merge the sorted halves
}

// Utility function to print the vector
void printVector(const std::vector<int>& arr) {
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example Usage 1
    std::vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    std::cout << "Original array 1: ";
    printVector(arr1);
    mergeSort(arr1, 0, arr1.size() - 1);
    std::cout << "Sorted array 1: ";
    printVector(arr1);

    std::cout << "\n";

    // Example Usage 2
    std::vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Original array 2: ";
    printVector(arr2);
    mergeSort(arr2, 0, arr2.size() - 1);
    std::cout << "Sorted array 2: ";
    printVector(arr2);

    std::cout << "\n";

    // Example Usage 3: Already sorted array
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "Original array 3: ";
    printVector(arr3);
    mergeSort(arr3, 0, arr3.size() - 1);
    std::cout << "Sorted array 3: ";
    printVector(arr3);

    std::cout << "\n";

    // Example Usage 4: Reverse sorted array
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    std::cout << "Original array 4: ";
    printVector(arr4);
    mergeSort(arr4, 0, arr4.size() - 1);
    std::cout << "Sorted array 4: ";
    printVector(arr4);

    std::cout << "\n";

    // Example Usage 5: Empty array
    std::vector<int> arr5 = {};
    std::cout << "Original array 5: ";
    printVector(arr5);
    mergeSort(arr5, 0, arr5.size() - 1); // Should handle gracefully
    std::cout << "Sorted array 5: ";
    printVector(arr5);

    std::cout << "\n";

    // Example Usage 6: Single element array
    std::vector<int> arr6 = {42};
    std::cout << "Original array 6: ";
    printVector(arr6);
    mergeSort(arr6, 0, arr6.size() - 1);
    std::cout << "Sorted array 6: ";
    printVector(arr6);

    return 0;
}
