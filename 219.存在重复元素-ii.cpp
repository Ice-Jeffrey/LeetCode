/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) != m.end()) {
                if(abs(m[nums[i]] - i) <= k)
                    return true;
                else 
                    m[nums[i]] = i;
            }
            else 
                m.insert(pair<int, int>(nums[i], i));
        }

        return false;
    }
};
// @lc code=end

