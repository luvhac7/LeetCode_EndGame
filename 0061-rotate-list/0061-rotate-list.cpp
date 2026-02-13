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
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head || !head->next || k == 0)
            return head;

        vector<int> x;
        ListNode* t = head;

        while(t) {
            x.push_back(t->val);
            t = t->next;
        }

        int n = x.size();
        k = k % n;          
        if(k == 0) return head;

        vector<int> v;
                for(int i = n - k; i < n; i++)
            v.push_back(x[i]);
        for(int i = 0; i < n - k; i++)
            v.push_back(x[i]);

        ListNode* dum = new ListNode(0);
        ListNode* cur = dum;

        for(int val : v) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }

        return dum->next;
    }
};