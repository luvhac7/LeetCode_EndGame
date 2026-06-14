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
    ListNode* partition(ListNode* head, int x) {
        l* less_dum=new l(0);
        l*less_tail=less_dum;
        l* great_dum=new l(0);
        l* great_tail=great_dum;
        l* cur=head;
        while(cur!=nullptr)
        {
            if(cur->val<x)
            {
                less_tail->next=cur;
                less_tail=cur;
            }
            else{
                great_tail->next=cur;
                great_tail=cur;
            }
            cur=cur->next;
        }
        great_tail->next=nullptr;
        less_tail->next=great_dum->next;
        return less_dum->next;
    }
};