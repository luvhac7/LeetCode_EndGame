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
    ListNode* rotateRight(ListNode* head, int k) {
        // if(!head || !head->next || k==0) return head;
        // l* tail;
        // int len=1;
        // for(tail=head;tail->next;tail=tail->next)
        //     ++len;
        // tail->next=head;//circle bna
        // int t=len-k%len;//us possition jispe rotaion karna h usko nikklo

        // for(int i=0;i<t;i++)
        //     tail=tail->next;
        // l* newi=tail->next;
        // tail->next=nullptr;
        // return newi;
        return f(head,k);
    }
private:
    l* f(l* head,int k)
    {
        if(!head||k==0 ||!head->next)
        {
            return head;
        }
        l* tail;int x=1;
        for(tail=head;tail->next;tail=tail->next)
            ++x;
        tail->next=head;
        int t=x-k%x;
        for(int i=0;i<t;i++)
            tail=tail->next;
        l* ans=tail->next;
        tail->next=nullptr;
        return ans;

        
    }
};