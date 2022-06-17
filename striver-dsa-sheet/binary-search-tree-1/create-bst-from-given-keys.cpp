class Solution {
   public:
    TreeNode* newNode(int x) {
        TreeNode* node = new TreeNode();
        node->val = x;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    TreeNode* arrayToBST(vector<int>& arr, int start, int end) {
        if (start > end) {
            return NULL;
        }

        int mid = (start + end) / 2;
        TreeNode* node = newNode(arr[mid]);

        node->left = arrayToBST(arr, start, mid - 1);
        node->right = arrayToBST(arr, mid + 1, end);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = arrayToBST(nums, 0, nums.size() - 1);
        return root;
    }
};