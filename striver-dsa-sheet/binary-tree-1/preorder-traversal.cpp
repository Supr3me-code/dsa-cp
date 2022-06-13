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
    void recur(vector<int> &result, TreeNode* root){
        if(root == NULL){
            return;
        }
        
        result.push_back(root->val);
        recur(result, root->left);
        recur(result, root-> right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recur(result, root);
        return result;
    }
};

//iterative

class Solution{
    public:
    vector<int> iterativePreorder(TreeNode* root){
        stck<int> st;
        vector<int> preorder;
        if(root==NULL) return preorder;
        TreeNode* node = root;
        st.push(node);
        while(!st.empty()){
            node = st.top();
            st.pop();
            preorder.push_back(node);
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }
        return preorder;
    }
}