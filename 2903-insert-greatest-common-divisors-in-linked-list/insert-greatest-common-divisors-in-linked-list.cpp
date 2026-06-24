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
    ListNode* insertGreatestCommonDivisors(ListNode* h) {
        if(!h || !h->next) return h;
        l* x=h;
        l* xx=h->next;
        while(xx)
        {
            int res=__gcd(x->val,xx->val);
            l* xxx=new l(res);
            x->next=xxx;
            xxx->next=xx;
            x=xx;
            xx=xx->next;
        }
        return h;
    }
};