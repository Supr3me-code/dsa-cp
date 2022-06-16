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
    bool compare(TreeNode* leftSide, TreeNode* rightSide) {
        if (leftSide == NULL || rightSide == NULL) return leftSide == rightSide;
        return (leftSide->val == rightSide->val) &&
               compare(leftSide->left, rightSide->right) &&
               compare(leftSide->right, rightSide->left);
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode* leftSide = root;
        TreeNode* rightSide = root;
        return compare(leftSide, rightSide);
    }
};