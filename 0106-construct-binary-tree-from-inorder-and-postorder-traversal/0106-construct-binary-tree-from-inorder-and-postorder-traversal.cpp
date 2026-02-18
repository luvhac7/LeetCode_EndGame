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
int find(vector<int>&a,int st,int end,int v)
{
    for(int i=st;i<=end;i++)
        if(a[i]==v) return i;
    return  -1;
}
t* build(vector<int>&in,vector<int>&post,int st,int end,int &pidx)
{
    if(st>end) return nullptr;
    t* node=new t(post[pidx]);
    pidx--;
    if(st==end) return node;
    int idx=find(in,st,end,node->val);
    node->right=build(in,post,idx+1,end,pidx);
    node->left=build(in,post,st,idx-1,pidx);
    return node;
}
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        int pidx=n-1;
        return build(in,post,0,n-1,pidx);
    }
};