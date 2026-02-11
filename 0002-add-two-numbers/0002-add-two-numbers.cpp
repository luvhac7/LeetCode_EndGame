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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode();
        ListNode* cur=temp;
        int cnt=0;
        while(l1||l2||cnt)
        {
            int x=cnt;
            if(l1)
            {
                cout<<"List1:"<<"->";
                cout<<l1->val<<" \n";
                x+=l1->val;
                l1=l1->next;
                cout<<endl;
            }
            if(l2)
            {
                cout<<"List2:"<<"->";
                cout<<l2->val<<" \n";
                x+=l2->val;
                l2=l2->next;
                cout<<endl;
                
            }
            cnt=x/10;cout<<x<<" \n";
            cur->next=new ListNode(x%10);
            cur=cur->next;
        }

        return temp->next;
    }
};