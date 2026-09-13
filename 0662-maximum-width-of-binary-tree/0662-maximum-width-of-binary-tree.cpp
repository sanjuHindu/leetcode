/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        using ull=unsigned long long;
        queue<pair<TreeNode*,ull>>q;
        q.push({root,0});
        unsigned long long ans=0;
        while(!q.empty()){
            int levelSize=q.size();
            ull first=q.front().second;
            ull last=first;
            for(int i=0;i<levelSize;i++){
                auto[node,index]=q.front();
                q.pop();
                index-=first;
                last=index;
                if(node->left){
                    q.push({node->left,2*index+1});
                }
                if(node->right){
                    q.push({node->right,2*index+2});
                }

            }
            ans=max(ans,last+1);

        }
        return static_cast<int>(ans);
        
    }
};