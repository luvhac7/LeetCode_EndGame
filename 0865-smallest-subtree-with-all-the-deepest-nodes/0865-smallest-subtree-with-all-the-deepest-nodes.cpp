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
    TreeNode* ans=NULL;//LCA
    int cnt=0;//maxdepth
    int solve(TreeNode* root,int i)
    {
        cnt=max(cnt,i);
        if(!root) return i;
        int east=solve(root->left,i+1);
        int west=solve(root->right,i+1);
        if(east==cnt && west==cnt)
        {
            ans=root;
        }
        return max(east,west);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};