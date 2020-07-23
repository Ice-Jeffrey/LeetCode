/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto start=s.begin();
        int len = 0;
        while(start<s.end()) {
            auto end = start + 1;
            string temp(start, end);
            while (end < s.end() && temp.find(*end) == string::npos) {
                temp += *end;
                end++;
            }
            if(temp.length() > len) {
                len = temp.length();
            }
            start++;
        }
        return len;
    }
};
// @lc code=end

