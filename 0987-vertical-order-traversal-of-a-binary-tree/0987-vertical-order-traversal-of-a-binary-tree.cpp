class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;

        // node, row, col
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();

            int row = pos.first;
            int col = pos.second;

            mp[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }

            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto &col : mp) {
            vector<int> temp;

            for (auto &row : col.second) {
                for (int val : row.second) {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};