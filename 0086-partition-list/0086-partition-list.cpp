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
             ListNode* partition(ListNode* head, int x) {
                     ListNode* left = new ListNode(0);   // list of nodes < x
                             ListNode* right = new ListNode(0);  // list of nodes >= x
                                     ListNode* lefttail = left;
                                             ListNode* righttail = right;

                                                     while (head != nullptr) {
                                                                 if (head->val < x) {
                                                                                 lefttail->next = head;     // ✅ use lefttail
                                                                                                 lefttail = lefttail->next;
                                                                                                             } else {
                                                                                                                             righttail->next = head;    // ✅ use righttail
                                                                                                                                             righttail = righttail->next;
                                                                                                                                                         }
                                                                                                                                                                     head = head->next;
                                                                                                                                                                             }

                                                                                                                                                                                     // connect the two lists
                                                                                                                                                                                             lefttail->next = right->next;
                                                                                                                                                                                                     righttail->next = nullptr;  // important to end the list

                                                                                                                                                                                                             return left->next;  // skip dummy node
                                                                                                                                                                                                                 }
                                                                                                                                                                                                                 };
                                                                                                                                                                                                                 