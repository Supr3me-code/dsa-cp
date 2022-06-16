/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        recursive(root, d);
        return d;
    }

    int recursive(TreeNode* root, int& d) {
        if (root == NULL) return 0;
        int ld = recursive(root->left, d);
        int rd = recursive(root->right, d);
        d = max(d, ld + rd);
        return max(ld, rd) + 1;
    }
};