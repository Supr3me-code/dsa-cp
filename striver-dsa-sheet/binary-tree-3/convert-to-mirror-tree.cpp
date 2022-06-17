void mirror(struct Node* node) {
    if (node == NULL) return;
    mirror(node->left);
    mirror(node->right);
    if (node->right != NULL && node->left == NULL) {
        node->left = node->right;
        node->right = NULL;
    } else if (node->right == NULL && node->left != NULL) {
        node->right = node->left;
        node->left = NULL;
    } else {
        struct Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }

    // code here
}