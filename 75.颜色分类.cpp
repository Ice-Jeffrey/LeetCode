/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count = {0, 0, 0};
        for(auto i=0; i<nums.size(); i++)
            count[nums[i]]++;
        for(int i=0; i<3; i++) {
            int start = 0;
            if(i != 0) {
                for(int j=0; j<i; j++)
                    start += count[j];
            }
            for(int j=0; j<count[i]; j++)
                nums[start+j] = i;
        }
    }
};
// @lc code=end

