class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root != NULL){
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            return 1 + max(leftDepth, rightDepth);
        }
        return 0;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if(abs(leftDepth - rightDepth) > 1){
            return false;
        }

        if(!isBalanced(root->left) || !isBalanced(root->right)){
            return false;
        }
        
        return true;
    }
};