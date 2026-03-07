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
typedef TreeNode N;
N* f(N* root,N* p,N* q)
{
    if(!root) return nullptr;
    if(root->val<p->val && root->val<q->val)
    {
        return f(root->right,p,q);
    }
    if(root->val>p->val && root->val>q->val)
    {
      return  f(root->left,p,q);
    }
    return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* rt, TreeNode* p, TreeNode* q){
        return f(rt,p,q);
    }
};