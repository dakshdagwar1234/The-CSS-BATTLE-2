
from typing import List

def quick_sort(arr: List[int]) -> List[int]:
    """
    Sorts a list of integers in ascending order using the Quick Sort algorithm.

    Quick Sort is a highly efficient, comparison-based sorting algorithm.
    It works by selecting a 'pivot' element from the array and partitioning
    the other elements into two sub-arrays, according to whether they are
    less than or greater than the pivot. The sub-arrays are then sorted recursively.

    Time Complexity:
        - Best Case: O(n log n)
        - Average Case: O(n log n)
        - Worst Case: O(n^2) (occurs when the pivot selection consistently
          results in highly unbalanced partitions, e.g., already sorted array)

    Space Complexity:
        - O(log n) on average due to recursion stack.
        - O(n) in the worst case.

    Args:
        arr: A list of integers to be sorted.

    Returns:
        A new list containing the sorted integers.
    """
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

if __name__ == "__main__":
    # Test cases
    test_arrays = [
        [],
        [1],
        [5, 2, 9, 1, 7],
        [3, 3, 3, 3, 3],
        [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        [-5, 0, 5, -10, 10],
        [1, 2, 3, 4, 5]
    ]

    for i, arr in enumerate(test_arrays):
        sorted_arr = quick_sort(arr)
        print(f"Original array {i+1}: {arr}")
        print(f"Sorted array {i+1}: {sorted_arr}")
        print("-" * 30)
