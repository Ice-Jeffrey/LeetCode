/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto temp1 = s.begin();
        auto temp2 = t.begin();

        while(temp2 != t.end() && temp1 != s.end()) {            
            if(*temp1 == *temp2) 
                temp1++;
            
            temp2++;
        }

        return temp1 == s.end();
    }
};
// @lc code=end

