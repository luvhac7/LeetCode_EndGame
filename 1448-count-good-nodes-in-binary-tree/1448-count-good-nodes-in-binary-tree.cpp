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
typedef TreeNode N;
void dfs(N* rt,int &cnt,int maxi)
{
    if(!rt) return;
    if(maxi<=rt->val)cnt++;
    maxi=max(rt->val,maxi);
    dfs(rt->left,cnt,maxi);
    dfs(rt->right,cnt,maxi);
}
    int goodNodes(TreeNode* root) {
        int cnt=0;
        dfs(root,cnt,INT_MIN);
        return cnt;
    }
};