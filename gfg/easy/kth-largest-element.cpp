// } Driver Code Ends
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
   public:
    void findInorder(vector<int>& inorder, Node* root) {
        if (root == NULL) return;
        findInorder(inorder, root->left);
        inorder.push_back(root->data);
        findInorder(inorder, root->right);
    }

    int kthLargest(Node* root, int k) {
        vector<int> inorder;
        findInorder(inorder, root);
        int s = inorder.size();
        return inorder[s - k];
    }
};
