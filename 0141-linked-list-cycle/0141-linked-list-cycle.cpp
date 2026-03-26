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
    bool hasCycle(ListNode *h) {
        if(!h) return false;
        L* t=h;
        L* p=h;
        while(p && p->next)
        {
            p=p->next->next;
            t=t->next;
            if(p==t) return true;
        }
        return false;
    }
};