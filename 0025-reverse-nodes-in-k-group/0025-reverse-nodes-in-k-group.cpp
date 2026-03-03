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
typedef ListNode ll;
//reverse
ll* rev(ll* head,ll* tail)
{
ll* prev=nullptr;
ll* cur=head;
while(cur!=tail)
{
    ll* nxt=cur->next;
    cur->next=prev;
    prev=cur;
    cur=nxt;
}
return  prev;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
      if(!head||k==1) return head;
      ll* dum=new ll(0);
      dum->next=head;
      ll* pre=dum;
      while(pre)
      { 
        ll* cur=pre;
        for(int i=0;i<k;i++)
        {
            if(cur->next==nullptr)
            {
                return dum->next;
            }
            cur=cur->next;
        }
        ll* node=pre->next;
        ll* nxt=cur->next;
        cur->next=nullptr;
        ll* revhead=rev(node,nullptr);
        pre->next=revhead;
        node->next=nxt;
        pre=node;
      }
      return dum->next;
    }
};