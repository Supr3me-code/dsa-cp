vector<int> leftView(Node* root) {
    vector<int> leftView;
    if (root == NULL) return leftView;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            level.push_back(node->data);
        }
        leftView.push_back(level[0]);
    }
    return leftView;
}

//--------

class Solution {
    vector<int> leftSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

   public:
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL) return;
        if (res.size == level) res.push_back(root->val);
        recursion(root->left, level + 1, res);
        recursion(root->right, level + 1, res);
    }
};