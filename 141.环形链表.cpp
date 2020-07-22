/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> m;
        int pos = -1;
        for(ListNode* temp=head; temp; temp=temp->next) {
            auto iter = m.find(temp);
            if(iter != m.end()) {
                return true;
            }
            else 
                m.insert(temp);
        }

        return false;
    }
};
// @lc code=end

