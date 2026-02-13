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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        vector<int>x;
        while(temp)
        {
            x.push_back(temp->val);temp=temp->next;
        }
        for(int i=0;i+k<=x.size();i+=k)
        {
            reverse(x.begin()+i,x.begin()+i+k);
        }
        ListNode* dum=new ListNode(0);
        ListNode* cur=dum;
        for(int i:x)
        {
            cur->next=new ListNode(i);
            cur=cur->next;
        }
        return dum->next;
    }
};