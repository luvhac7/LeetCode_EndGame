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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<N*>q;q.push(root);
        //intialize queue with rt node for bfs
        while(!q.empty())
        {
            vector<int>lvl;
            int lvl_size=q.size();
            for(int i=0;i<lvl_size;i++)
            {
                N* curr=q.front();
                q.pop();
                lvl.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            res.push_back(lvl);
        }
        return  res;
    }
};