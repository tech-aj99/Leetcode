class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root != NULL){
            int leftDepth = minDepth(root->left);
            int rightDepth = minDepth(root->right);

            if(root->left == NULL){
                return 1 + rightDepth;
            }

            if(root->right == NULL){
                return 1 + leftDepth;
            }

            return 1 + min(leftDepth, rightDepth);
        }
        return 0;
    }
};