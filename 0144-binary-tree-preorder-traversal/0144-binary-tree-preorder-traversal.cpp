class Solution {
public:
    int preorder(TreeNode* root, vector<int> &ans){
        if(root != NULL){
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
        return 0;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        preorder(root, ans);
        return ans;    
    }
};