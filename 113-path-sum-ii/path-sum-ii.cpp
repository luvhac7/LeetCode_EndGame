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
typedef TreeNode l;
vector<vector<int>>path;
vector<int>res;
void dfs(l* node,int sum)
{
if(!node) return;
res.push_back(node->val);
if(!node->left && !node->right && node->val==sum) path.push_back(res);
dfs(node->left,sum-node->val);
dfs(node->right,sum-node->val);
res.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* rt, int tar) {
        dfs(rt,tar);
        return path;
    }
};