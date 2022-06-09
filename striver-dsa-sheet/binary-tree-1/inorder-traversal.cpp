//recursive
class Solution {
public:
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root==NULL){
            return inorder;
        }
   
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        
        
        return inorder;
    }
};


//iterative
class Solution{
    public:
    vector<int> IterativeInorderTraversal(TreeNode* root){
        vector<int> inorder;
        stack<int> st;
        TreeNode* node = root;
        st.push(root);
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node);
                st.push(node->right);
            }
        }
        return inorder;
    }

}