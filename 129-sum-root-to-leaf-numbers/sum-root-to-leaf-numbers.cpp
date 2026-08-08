class Solution {
private:
    void solve(TreeNode* root, int curr, int &ans) {
        if(root == NULL)
            return;
        curr = curr * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            ans += curr;
            return;
        }
        
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }
};