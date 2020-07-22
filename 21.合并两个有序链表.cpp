/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sentinal = new ListNode(-1);
        ListNode *temp1=l1, *temp2=l2, *temp=sentinal;
        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {
                temp->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            }
            else {
                temp->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(!temp1)
            temp->next = temp2;
        else if(!temp2)
            temp->next = temp1;

        ListNode* target = sentinal->next;
        delete sentinal;
        return target;
    }
};
// @lc code=end

