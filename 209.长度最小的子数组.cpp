/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = -1, end = 0;
        int sum = 0;
        int len = INT_MAX;
        
        while(end < nums.size()) {
            sum += nums[end];
            while (sum >= s) {
                if(end-start < len)
                    len = end - start;
                start++;
                sum -= nums[start];
            }  
            end++;                       
        }
        
        return len == INT_MAX ? 0 : len;
    }
};
// @lc code=end

