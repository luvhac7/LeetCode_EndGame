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
              int acc(TreeNode* root) noexcept {
                      if (!root) return 0;
                              return root->val += acc(root->left) + acc(root->right);
                                  }

                                      int total = 0;
                                          int mid = 0;

                                              int dfs(TreeNode* node) noexcept {
                                                      if (!node) return mid;
                                                              int x = max(node->val, total - node->val) - mid;
                                                                      return min(x, min(dfs(node->left), dfs(node->right)));
                                                                          }

                                                                              int maxProduct(TreeNode* root) noexcept {
                                                                                      total = acc(root);
                                                                                              mid = total / 2;
                                                                                                      int x = dfs(root);
                                                                                                              int a = x + mid, b = total - a;
                                                                                                                      return (int64_t{a} * b) % 1'000'000'007u;
                                                                                                                          }
                                                                                                                          };