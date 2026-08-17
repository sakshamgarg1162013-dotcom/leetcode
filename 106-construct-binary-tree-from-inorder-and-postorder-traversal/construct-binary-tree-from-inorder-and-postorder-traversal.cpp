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
    TreeNode* build(vector<int>& postorder,unordered_map<int,int>& mp,int& pre,int left,int right) {

        if(left > right)
            return NULL;

        int rootVal = postorder[pre--];
        int index = mp[rootVal];

        TreeNode* root = new TreeNode(rootVal);

        root->right = build(postorder, mp, pre, index + 1, right);
        root->left = build(postorder, mp, pre, left, index - 1);
        

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int pre = postorder.size()-1;

        return build(postorder, mp, pre, 0, inorder.size() - 1);

    }
};