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
typedef ListNode L;

    ListNode* mergeKLists(vector<ListNode*>& lst) {
auto comp=[](const L*a,const L*b){return a->val>b->val;};
std::priority_queue<L*,vector<L*>,decltype(comp)>minh(comp);
for(L* i:lst)
{
    if(i!=nullptr)
    {
        minh.push(i);
    }
}
L dum(0);
L* cur=&dum;
while(!minh.empty())
{
    L* mini=minh.top();
    minh.pop();
    cur->next=mini;
    cur=cur->next;
    if(mini->next!=nullptr)
    {
        minh.push(mini->next);
    }
}
return dum.next;
    }
};