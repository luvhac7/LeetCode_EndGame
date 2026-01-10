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
    int y,n;
};
class Solution {
public:
    T f(TreeNode* root)
    {
        if(root==nullptr)
            return {0,0};
        T l=f(root->left);
        T r=f(root->right);
        T cur;
        cur.y=root->val+l.n+r.n;
        cur.n=max(l.y,l.n)+max(r.y,r.n);
        return cur;
    }
    int rob(TreeNode* root) {
        T res=f(root);
        return max(res.y,res.n);
    }
};