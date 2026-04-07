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
typedef ListNode l;
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        l* tail;
        int len=1;
        for(tail=head;tail->next;tail=tail->next)
            ++len;
        tail->next=head;//circle bna
        int t=len-k%len;
        for(int i=0;i<t;i++)
            tail=tail->next;
        l* newi=tail->next;
        tail->next=nullptr;
        return newi;
    }
};