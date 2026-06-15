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
    void reorderList(ListNode* h) {
        if(!h || !h->next) return;vector<int>a;
        l*cur=h;
        while(cur){
            a.push_back(cur->val);
            cur=cur->next;
        }
        vector<int>ans;
        int left=0,right=a.size()-1;
        while(left<=right){
            if(left==right){
                ans.push_back(a[left]);
                break;
            }
            ans.push_back(a[left]);
            ans.push_back(a[right]);
            left++;
            right--;
        }
        cur=h;
        int i=0;
        while(cur){
            cur->val=ans[i];
            cur=cur->next;
            i++;
        }
    }
};