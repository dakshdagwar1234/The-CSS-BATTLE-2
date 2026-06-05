#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 3) {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
        // Skip duplicate elements for i
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate elements for left
                while (left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                // Skip duplicate elements for right
                while (left < right && nums[right] == nums[right-1]) {
                    right--;
                }

                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else { // sum > 0
                right--;
            }
        }
    }
    return result;
}

int main() {
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result1 = threeSum(nums1);
    std::cout << "Triplets for nums1: " << std::endl;
    for (const auto& triplet : result1) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {0, 1, 1};
    std::vector<std::vector<int>> result2 = threeSum(nums2);
    std::cout << "Triplets for nums2: " << std::endl;
    for (const auto& triplet : result2) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> nums3 = {0, 0, 0};
    std::vector<std::vector<int>> result3 = threeSum(nums3);
    std::cout << "Triplets for nums3: " << std::endl;
    for (const auto& triplet : result3) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
