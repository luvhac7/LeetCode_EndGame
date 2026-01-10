/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 struct T{
    int yes;
    int no;
 };
class Solution {
public:
    int rob(TreeNode* root) {
        const auto &[yes,no]=solve(root);
        return max(yes,no);
    }
    T solve(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }
        const T l=solve(root->left);
        const T r=solve(root->right);
        return {root->val+l.no+r.no,max(l.no,l.yes)+max(r.no,r.yes)};
    }
};