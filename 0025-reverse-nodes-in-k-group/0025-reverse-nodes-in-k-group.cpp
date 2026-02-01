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
ListNode* solve(ListNode* t,int k)
{
    k-=1;
    while(t && k>0)
    {
        k--;
        t=t->next;
    }
    return t;
}
    ListNode* rev(ListNode* t) {
        ListNode* nn = NULL;
        while (t) {
            ListNode* nxt = t->next;
            t->next = nn;
            nn = t;
            t = nxt;
        }
        return nn;
    }
    ListNode* reverseKGroup(ListNode* h, int k) {
        ListNode* t = h;
        ListNode* p = NULL;

        while (t) {
            ListNode* nn = solve(t, k);
            if (!nn) {
                if (p) p->next = t;
                break;
            }

            ListNode* nxtn = nn->next;
            nn->next = NULL;

            ListNode* newHead = rev(t);

            if (t == h) h = newHead;
            else p->next = newHead;

            p = t;
            t = nxtn;
        }
        return h;
    }
};