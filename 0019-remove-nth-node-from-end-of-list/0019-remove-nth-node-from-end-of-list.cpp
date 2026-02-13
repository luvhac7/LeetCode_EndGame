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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>x;
        ListNode* temp=head;
        while(temp)
        {
            x.push_back(temp->val);temp=temp->next;
        }
        
        // int rem=x[x.size()-n];
        // bool f=true;
         vector<int>res;
         int idx = x.size() - n;
        x.erase(x.begin() + idx);

        ListNode* p1 = new ListNode(0);
ListNode* p2= p1;

for(int i = 0; i < x.size(); i++)
{
    p2->next = new ListNode(x[i]);
    p2 =p2->next;
}

return p1->next;
    }
};