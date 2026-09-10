class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If either tree is empty
        if (p == NULL || q == NULL) {
            return p == q;
        }

        // Compare left subtree
        bool isLeftSame = isSameTree(p->left, q->left);

        // Compare right subtree
        bool isRightSame = isSameTree(p->right, q->right);

        // Compare current values
        return isLeftSame && isRightSame && (p->val == q->val);
    }
};