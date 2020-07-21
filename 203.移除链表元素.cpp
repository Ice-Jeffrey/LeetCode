/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 方法：手动添加头结点，即哨兵结点
        ListNode* Sentinal = new ListNode(-1);
        Sentinal->next = head;

        for(auto temp = Sentinal; temp && temp->next;) {
            if(temp->next->val == val) {
                ListNode* tempnode = temp->next;
                temp->next = temp->next->next;
                delete tempnode;
            }
            else 
                temp = temp->next;
        }

        head = Sentinal->next;
        delete Sentinal;
        return head;
    }
};
// @lc code=end

