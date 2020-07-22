/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// 也可使用二分法，则复杂度为o(logn)，使用该方法复杂度为o(n)

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] < min)
                min = nums[i];
            else if(nums[i] > min)
                break;
        }

        return min;
    }
};
// @lc code=end

