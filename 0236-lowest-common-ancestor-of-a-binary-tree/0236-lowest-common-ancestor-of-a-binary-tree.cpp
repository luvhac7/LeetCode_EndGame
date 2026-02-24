/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
typedef TreeNode t;
t* f(t* root,t* p,t* q)
{
    if(!root|| root==p||root==q ) return root;
    t* l=f(root->left,p,q);
    t* r=f(root->right,p,q);
    if(l&&r) return root;
    return l ? l:r;
   // return max(l,r==l ? l:r;    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};