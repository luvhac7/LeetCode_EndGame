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
typedef ListNode L;
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        L* x=head;
        L* y=head;
        while(x &&  x->next)
        {
            y=y->next;x=x->next->next;
            if(x==y) return true;
        }
        return false;
    }
};