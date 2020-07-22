/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int pivot;

        while(low < high) {
            pivot = low + (high - low) / 2;
            if(nums[pivot] < nums[high])
                high = pivot;
            else if(nums[pivot] > nums[high])
                low = pivot + 1;
        }

        return nums[low];
    }
};
// @lc code=end

