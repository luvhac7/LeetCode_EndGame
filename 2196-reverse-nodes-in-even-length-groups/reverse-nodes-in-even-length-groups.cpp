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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>v;
        l* cur=head;
        while(cur)
        {
            v.push_back(cur->val);
            cur=cur->next;
        }
        int len=v.size();
        int start=0;
        int grp_size=1;
        while(start<len)
        {
            int actual_grp_size=min(len-start,grp_size);
            bool even=(actual_grp_size & 1)==0;
            if(even)
            {
                reverse(v.begin()+start,v.begin()+start+actual_grp_size);
            }
            start+=actual_grp_size;
            grp_size++;
        }
        cur=head;
        for(int i:v)
        {
            if(cur)
            {
                cur->val=i;
                cur=cur->next;
            }
        }
        return head;
    }
};