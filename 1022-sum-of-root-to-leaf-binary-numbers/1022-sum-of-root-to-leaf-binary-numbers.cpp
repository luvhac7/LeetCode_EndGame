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
class Solution {
public:
typedef TreeNode t;
int f(t* rt,int x)
{
    if(!rt) return 0;
    x=x*2+rt->val;
    if(rt->left==rt->right) return x;
    return f(rt->left,x)+f(rt->right,x);
}
    int sumRootToLeaf(TreeNode* root) {
        return f(root,0);
    }
};