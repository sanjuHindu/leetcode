class Solution {
public:
    int index = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }

private:
    TreeNode* build(vector<int>& preorder, int minVal, int maxVal) {
        // No more elements
        if (index >= preorder.size())
            return nullptr;

        int value = preorder[index];

        // Current value doesn't belong to this subtree
        if (value <= minVal || value >= maxVal)
            return nullptr;

        // Create current root
        TreeNode* root = new TreeNode(value);
        index++;

        // Recursively build left and right subtrees
        root->left = build(preorder, minVal, value);
        root->right = build(preorder, value, maxVal);

        return root;
    }
};