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
    int ts=0;
    long res=0;
    int maxProduct(TreeNode* root)
    {
        ts=getts(root);
        getss(root);
        return res%(int)(1e9+7);
    }
    int getts(TreeNode* node){
        if(!node) return 0;
        return node->val+getts(node->left)+getts(node->right);
    }
    long getss(TreeNode* node) {
        if(!node) return 0;
        long left=getss(node->left);
        long right=getss(node->right);
        long subtree=node->val+left+right;
        res=max(res,subtree*(ts-subtree));
        return subtree;
    }
};