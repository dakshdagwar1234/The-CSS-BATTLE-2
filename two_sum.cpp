#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // For std::pair

// Function to find two numbers that add up to the target using a hash map (optimized O(N))
std::pair<int, int> twoSumOptimized(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // Map to store number and its index
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int complement = target - nums[i];
        // Check if the complement exists in the map
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        // If not, add the current number and its index to the map
        numMap[nums[i]] = i;
    }
    // If no solution is found, return an invalid pair
    return {-1, -1};
}

int main() {
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::pair<int, int> result1 = twoSumOptimized(nums1, target1);
    if (result1.first != -1) {
        std::cout << "For nums = {2, 7, 11, 15}, target = 9: Indices are "
                  << result1.first << ", " << result1.second << std::endl;
    } else {
        std::cout << "No two sum solution for nums = {2, 7, 11, 15}, target = 9" << std::endl;
    }

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::pair<int, int> result2 = twoSumOptimized(nums2, target2);
    if (result2.first != -1) {
        std::cout << "For nums = {3, 2, 4}, target = 6: Indices are "
                  << result2.first << ", " << result2.second << std::endl;
    } else {
        std::cout << "No two sum solution for nums = {3, 2, 4}, target = 6" << std::endl;
    }

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::pair<int, int> result3 = twoSumOptimized(nums3, target3);
    if (result3.first != -1) {
        std::cout << "For nums = {3, 3}, target = 6: Indices are "
                  << result3.first << ", " << result3.second << std::endl;
    } else {
        std::cout << "No two sum solution for nums = {3, 3}, target = 6" << std::endl;
    }

    std::vector<int> nums4 = {1, 2, 3, 4, 5};
    int target4 = 10; // No solution
    std::pair<int, int> result4 = twoSumOptimized(nums4, target4);
    if (result4.first != -1) {
        std::cout << "For nums = {1, 2, 3, 4, 5}, target = 10: Indices are "
                  << result4.first << ", " << result4.second << std::endl;
    } else {
        std::cout << "No two sum solution for nums = {1, 2, 3, 4, 5}, target = 10" << std::endl;
    }

    return 0;
}
