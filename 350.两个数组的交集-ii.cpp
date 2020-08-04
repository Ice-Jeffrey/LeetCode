/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());


        int temp1 = 0, temp2 = 0;
        while(temp1 < nums1.size() && temp2 < nums2.size()) {
            if(nums1[temp1] == nums2[temp2]) {
                vec.push_back(nums1[temp1]);
                temp1++;
                temp2++;
            }
            else if(nums1[temp1] < nums2[temp2])
                temp1++;
            else if(nums1[temp1] > nums2[temp2])
                temp2++;
        }

        return vec;
    }
};
// @lc code=end

