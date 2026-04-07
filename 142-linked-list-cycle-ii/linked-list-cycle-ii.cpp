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
typedef ListNode l;
    ListNode *detectCycle(ListNode *head) {
        l* x=head;
        l* y=head;
        if(!head)return nullptr;
        while(x && x->next)
        {

            y=y->next;
            x=x->next->next;
            if(y==x)
            {
                y=head;
                while(y!=x)
                {
                    y=y->next;
                    x=x->next;
                }
                return y;
            }
        }
        return nullptr;
    }
};