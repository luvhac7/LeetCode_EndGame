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
    ListNode* swapPairs(ListNode* head) {
        return f(head);
    }

    private:
    l* f(l* head)
    {
        int len=getlen(head);
        l dum(0,head);
        l* prev=&dum;
        l*curr=head;
        for(int i=0;i<len/2;i++)
        {
            l* next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            prev=curr;
            curr=curr->next;
        }
        return dum.next;
    }
        int getlen(l* head)
        {
            int len=0;
            for(l*cur=head;cur;cur=cur->next)
            {
                len++;
            }
            return len;
        }
};