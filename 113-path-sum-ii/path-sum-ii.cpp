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
private:
    void sum(TreeNode* root, int t, vector<int> &path,vector <vector<int>> &ans){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        t-=root->val;
        if(root->left==NULL && root->right==NULL){
            if(t==0){
                ans.push_back(path);
                
            }
            path.pop_back();
            return;  
        }
        sum(root->left,t,path,ans);
        sum(root->right,t,path,ans);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <vector<int>> ans;
        vector <int> path;
        sum(root,targetSum,path,ans);
        return ans;
    }
};