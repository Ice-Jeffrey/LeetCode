/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        for(ListNode* temp=head; temp && temp->next; ) {
            if(temp->val == temp->next->val) {
                ListNode* toBeDeleted = temp->next;
                temp->next = temp->next->next;
                delete toBeDeleted;
            }
            else
                temp = temp->next;            
        }

        return head;
    }
};
// @lc code=end

