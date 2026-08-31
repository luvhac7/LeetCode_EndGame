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
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        vector<int>a;
        while(h){
            a.push_back(h->val);h=h->next;
        }
        vector<int>cp;int n=a.size();
        for(int i=1;i<n-1;i++){
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                cp.push_back(i);
            }
            else if(a[i]<a[i-1] && a[i]<a[i+1]){
                cp.push_back(i);
            }
        }
        int m=cp.size();
        if(m<2) return {-1,-1};
        int mini=INT_MAX,maxi=cp[m-1]-cp[0];
        for(int i=1;i<m;i++){
            mini=min(mini,cp[i]-cp[i-1]);
        }
        return {mini,maxi};
    }
};