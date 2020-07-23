/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero =  nums.size() - 1;
        while (nonzero >= 0 && nums[nonzero] == 0) 
            nonzero--;
        
        for(int i=nonzero-1; i>=0; i--) {
            if(nums[i] == 0) {
                for(int j=i; j<nonzero; j++) 
                    nums[j] = nums[j+1];
                nums[nonzero] = 0;
                nonzero--;
            }
        }
    }
};
// @lc code=end

