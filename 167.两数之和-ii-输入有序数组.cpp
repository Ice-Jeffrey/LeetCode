/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        multimap<int, int> m;
        for(auto i=0; i<numbers.size(); i++) 
            m.insert(pair<int, int>(numbers[i], i));
        for(int i=0; i<numbers.size(); i++) {
            auto iter = m.find(target-numbers[i]);
            if(iter != m.end() && iter->second != i) {
                int temp1 = iter->second;
                int temp2 = i;
                if(temp1 > temp2) {
                    int temp = temp1;
                    temp1 = temp2;
                    temp2 = temp;
                }
                return vector<int>{temp1+1, temp2+1};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

