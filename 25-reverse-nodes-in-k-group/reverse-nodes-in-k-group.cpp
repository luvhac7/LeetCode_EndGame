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
    ListNode* reverseKGroup(ListNode* head, int k) {
        return f(head,k);
    }
   private:
        l* f(l* head,int k)
        {
            if(!head) return nullptr;
            l* tail=head;
            for(int i=0;i<k;i++){
                if(tail==nullptr)
                    return head;
                tail=tail->next;
        }
        l* newi=reverse(head,tail);
        head->next=f(tail,k);
        return newi;
        }
        l* reverse(l* head,l* tail)
        {
            l* prev=nullptr;
            l* cur=head;
            while(cur!=tail)
            {
                l* next=cur->next;
                cur->next=prev;
                prev=cur;
                cur=next;
            }
            return prev;
        }
};