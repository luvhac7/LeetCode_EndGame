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
    void swapp(ListNode* head)
    {
        if(!head || !head->next) return;
        swap(head->val,head->next->val);
        swapp(head->next->next);
    }
    ListNode* swapPairs(ListNode* head) {
        swapp(head);
        return head;
    }
};