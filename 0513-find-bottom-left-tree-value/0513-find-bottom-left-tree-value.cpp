
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = root->val;

        while (!q.empty()) {
            int size = q.size();

            // First node of the current level
            ans = q.front()->val;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
