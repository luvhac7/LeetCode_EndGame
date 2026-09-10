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
int sum(TreeNode* root){
    if(root==NULL)return 0;
    int l=sum(root->left);
    int r=sum(root->right);
    return root->val+l+r;
}
int count_nodes(TreeNode* root){
    if(root==NULL)return 0;
    int l=count_nodes(root->left);
    int r=count_nodes(root->right);
    return 1+l+r;
}
int f(TreeNode* root){
    if(root==NULL)return 0;
    int curr=0;
    int tar=sum(root)/count_nodes(root);
    if(root->val==tar){
        curr=1;
    }
    int l=f(root->left);
    int r=f(root->right);
    return curr+l+r;
}
    int averageOfSubtree(TreeNode* root) {
        int res=f(root);
        return res;       
    }
};