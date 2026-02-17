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
t* f(t* rt)
{
    if(!rt)return nullptr;
    swap(rt->left,rt->right);
    f(rt->left);
    f(rt->right);
    return rt;
}
    TreeNode* invertTree(TreeNode* root) {
        return f(root);
    }
};