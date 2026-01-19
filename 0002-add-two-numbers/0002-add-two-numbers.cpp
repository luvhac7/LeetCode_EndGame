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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dum=new ListNode(0);
        ListNode* res=dum;

        int ttl=0,carr=0;
        while(l1||l2||carr)
        {
            ttl=carr;
            if(l1)
            {
                ttl+=l1->val;l1=l1->next;
            }
            if(l2)
            {
                ttl+=l2->val;l2=l2->next;
            }
            carr=ttl/10;
            res->next=new ListNode(ttl%10);
            res=res->next;
        }
        return dum->next;
    }
};