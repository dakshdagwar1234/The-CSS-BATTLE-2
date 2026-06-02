from typing import List

def insertion_sort(arr: List[int]) -> List[int]:
    """
    Sorts a list of integers in ascending order using the Insertion Sort algorithm.

    Insertion sort iterates, consuming one input element each repetition, and growing
    a sorted output list. At each iteration, insertion sort removes one element from
    the input data, finds the location it belongs within the sorted list, and inserts it there.

    Args:
        arr: A list of integers to be sorted.

    Returns:
        A new list containing the sorted integers.
    """
    n = len(arr)
    # Create a copy to avoid modifying the original list in place
    sorted_arr = arr[:]

    for i in range(1, n):
        key = sorted_arr[i]
        j = i - 1
        # Move elements of sorted_arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and key < sorted_arr[j]:
            sorted_arr[j + 1] = sorted_arr[j]
            j -= 1
        sorted_arr[j + 1] = key
    return sorted_arr

if __name__ == "__main__":
    # Example Usage
    unsorted_list = [12, 11, 13, 5, 6]
    print(f"Original list: {unsorted_list}")
    sorted_list = insertion_sort(unsorted_list)
    print(f"Sorted list: {sorted_list}")

    unsorted_list_2 = [64, 25, 12, 22, 11]
    print(f"Original list: {unsorted_list_2}")
    sorted_list_2 = insertion_sort(unsorted_list_2)
    print(f"Sorted list: {sorted_list_2}")

    empty_list: List[int] = []
    print(f"Original list: {empty_list}")
    sorted_empty_list = insertion_sort(empty_list)
    print(f"Sorted list: {sorted_empty_list}")

    single_element_list = [42]
    print(f"Original list: {single_element_list}")
    sorted_single_element_list = insertion_sort(single_element_list)
    print(f"Sorted list: {sorted_single_element_list}")
