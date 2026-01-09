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
int md=0;
TreeNode* x=NULL;
    int dfs(TreeNode* root,int d)
    {
        md =max(md,d);
        if(!root) return d;
        int l=dfs(root->left,d+1);
        int r=dfs(root->right,d+1);
        if(md==l && md==r)
        {
            x=root;
        }
        return max(l,r);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return x;
    }
};