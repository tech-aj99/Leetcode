class Solution {
public:
    int postorder(TreeNode* root, vector<int> &ans){
        if(root != NULL){
            postorder(root->left, ans);
            postorder(root->right, ans);
            ans.push_back(root->val);
        }
        return 0;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postorder(root, ans);
        return ans;    
    }
};