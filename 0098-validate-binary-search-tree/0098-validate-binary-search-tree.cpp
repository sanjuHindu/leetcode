class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr)
            return true;

        // Current node must be strictly within its allowed range
        if (node->val <= minVal || node->val >= maxVal)
            return false;

        // Left subtree: values must be smaller than current node
        // Right subtree: values must be greater than current node
        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }
};