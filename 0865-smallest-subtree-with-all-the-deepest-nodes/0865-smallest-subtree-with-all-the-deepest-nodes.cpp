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
    int maxi=0;
    TreeNode* ans=NULL;
    int solve(TreeNode* root,int i)
    {
        maxi=max(maxi,i);
        if(!root) return i;
        int lf=solve(root->left,i+1);
        int rf=solve(root->right,i+1);
        if(lf==maxi && rf==maxi)
        {
            ans=root;
        }
        return max(lf,rf);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};