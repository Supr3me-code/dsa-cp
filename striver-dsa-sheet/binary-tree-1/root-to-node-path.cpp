/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool recursion(TreeNode* A, int B, vector<int>& res) {
    if (!A) return false;
    res.push_back(A->val);
    if (A->val == B) return true;
    if (recursion(A->left, B, res) || recursion(A->right, B, res)) return true;
    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if (A == NULL) {
        return res;
    }
    recursion(A, B, res);
    return res;
}
