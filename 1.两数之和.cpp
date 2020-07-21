/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> m;
        for(auto i=0; i<nums.size(); i++) 
            m.insert(pair<int,int>(nums[i], i));
        
        vector<int> v;
        for(auto iter=m.begin(); iter!=m.end(); iter++) {
            int temp = target - iter->first;
            auto it = m.find(temp);
            if(it != m.end() && it->second != iter->second) {
                v.push_back(iter->second);
                v.push_back(it->second);
                sort(v.begin(), v.end());
                break;
            }
        }

        return v;
    }
};
// @lc code=end

