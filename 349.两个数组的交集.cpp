/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec(0);
        set<int> s;
        for(auto i: nums1) 
            s.insert(i);
        for(auto item: nums2) {
            if(s.find(item) != s.end() && find(vec.begin(), vec.end(), item) == vec.end()) 
                vec.push_back(item);
        }

        return vec;
    }
};
// @lc code=end

