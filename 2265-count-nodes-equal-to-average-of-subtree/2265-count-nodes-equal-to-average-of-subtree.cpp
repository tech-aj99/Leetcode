class Solution {
public:
    int getSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return root->val + getSum(root->left) + getSum(root->right);
    }

    int getCount(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + getCount(root->left) + getCount(root->right);
    }

    void dfs(TreeNode* root, int &ans){
        if(root == NULL){
            return;
        }
        
        int sum = getSum(root);
        int count = getCount(root);

        int avg = sum / count;

        if(avg == root->val){
            ans++;
        }

        dfs(root->left, ans);
        dfs(root->right, ans);
    }


    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        dfs(root, ans);

        return ans;
    }
};