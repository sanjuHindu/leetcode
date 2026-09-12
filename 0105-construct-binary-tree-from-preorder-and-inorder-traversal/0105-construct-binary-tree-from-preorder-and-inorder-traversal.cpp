class Solution {
public:
    unordered_map<int, int> inMap;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Store inorder indices for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;

        // First element of preorder is the root
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inMap[rootValue];

        // Build left subtree
        root->left = build(preorder, left, rootIndex - 1);

        // Build right subtree
        root->right = build(preorder, rootIndex + 1, right);

        return root;
    }
};