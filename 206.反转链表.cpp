/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newList = NULL;
        for(auto temp = head; temp != NULL; temp = temp->next) {
            ListNode* tempnode;
            tempnode = new ListNode;
            tempnode->next = NULL;
            tempnode->val = temp->val;
            tempnode->next = newList;
            newList = tempnode;
        }

        // for(auto node = newList; node != NULL; node = node->next)
        //     cout << node->val << " ";
        // cout << endl;

        return newList;
    }
};
// @lc code=end

