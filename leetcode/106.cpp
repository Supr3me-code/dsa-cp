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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        map<int, int> imap;
        for (int i = 0; i < inorder.size(); ++i) imap[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                               postorder.size() - 1, imap);
    }
    TreeNode* buildTreePostIn(vector<int>& inorder, int inStart, int inEnd,
                              vector<int>& postorder, int postStart,
                              int postEnd, map<int, int>& imap) {
        if (postStart > postEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = imap[postorder[postEnd]];
        root->left =
            buildTreePostIn(inorder, inStart, inRoot - 1, postorder, postStart,
                            postStart + inRoot - inStart - 1, imap);
        root->right =
            buildTreePostIn(inorder, inRoot + 1, inEnd, postorder,
                            postStart + inRoot - inStart, postEnd - 1, imap);

        return root;
    }
};