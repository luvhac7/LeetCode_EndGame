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
l* copy(vector<int>&a)
{
    int n=a.size();
    if(a.empty()) return nullptr;
    l* head=new l(a[0]);
    l* cur=head;
    for(int i=1;i<n;i++)
    {
        cur->next=new l(a[i]);
        cur=cur->next;
    }
    return head;
}
    ListNode* deleteMiddle(ListNode* head) {
        l* cur=head;vector<int>a,ans;
        while(cur){
            a.push_back(cur->val);cur=cur->next;
        }
        for(int i=0;i<a.size();i++){
            if(i==a.size()/2) continue;
            ans.push_back(a[i]);
        }
        l* res=copy(ans);
        return res;
    }
};