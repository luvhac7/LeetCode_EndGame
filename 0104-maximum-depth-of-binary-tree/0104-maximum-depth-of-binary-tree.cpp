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
typedef TreeNode T;
int f(T* rt)
{
    if(!rt) return 0;
    int l=f(rt->left);
    int r=f(rt->right);
    return 1+max(l,r);
}
    int maxDepth(TreeNode* rt) {
        return f(rt);
    }
};