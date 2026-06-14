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
    int pairSum(ListNode* h) {
        l *f=h, *s=f;
        l* rev=NULL,*nn;
        while(f)
        {
            f=f->next->next;
            nn=s->next;
            s->next=rev;
            rev=s;
            s=nn;
        }
        int ans=0;
        while(s)
        {
            int x=rev->val;
            rev=rev->next;
            ans=max(ans,x+(s->val));
            s=s->next;
        }
        return ans;
    }
};