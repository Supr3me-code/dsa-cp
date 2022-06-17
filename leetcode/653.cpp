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
    void findInorder(vector<int>& inorder, TreeNode* root) {
        if (root == NULL) return;
        findInorder(inorder, root->left);
        inorder.push_back(root->val);
        findInorder(inorder, root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        findInorder(inorder, root);

        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++) {
            int required = k - inorder[i];
            if (um.find(required) != um.end()) {
                return true;
            } else {
                um[inorder[i]] = i;
            }
        }
        return false;
    }
};