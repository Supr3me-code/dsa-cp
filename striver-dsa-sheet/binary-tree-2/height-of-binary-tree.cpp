class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);

        if (left_height < right_height) {
            return right_height + 1;
        } else {
            return left_height + 1;
        }
    }
};