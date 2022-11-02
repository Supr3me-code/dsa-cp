/**********************************************************
    Following is the Binary Tree Node class structure.

    template <typename T>
    class BinaryTreeNode {
    public :
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }
    };

***********************************************************/

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1,
                                     int node2, int node3) {
    if (!root) return NULL;
    if (root->data == node1 || root->data == node2 || root->data == node3)
        return root;
    BinaryTreeNode<int>* a = lcaOfThreeNodes(root->left, node1, node2, node3);
    BinaryTreeNode<int>* b = lcaOfThreeNodes(root->right, node1, node2, node3);
    if (a && !b)
        return a;
    else if (!a && b)
        return b;
    else if (!a && !b)
        return NULL;
    else
        return root;
    // Write your code here.
}
