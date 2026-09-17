class Solution{
public:
    int kthSmallest(TreeNode*root,int k){
        return inorder(root,k);
    }
    private:
     int inorder(TreeNode*root,int & k){
        if(root==nullptr){
            return -1;
        }
        int left=inorder(root->left,k);
        if(k==0){
            return left;
        }
        k--;
        if(k==0){
            return root->val;
        }
        return inorder(root->right,k);
     }
};