class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        // Left
        inorder(root->left);

        // Current node
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
            }

            second = root;
        }

        prev = root;

        // Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        // Swap the two incorrect values
        swap(first->val, second->val);
    }
};