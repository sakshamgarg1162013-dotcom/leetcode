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
    TreeNode* build(vector<int>& preorder,vector<int>& postorder,unordered_map<int, int>& mp,int& pre,int left,int right) {

        if(left > right || pre >= preorder.size())
            return NULL;

        int rootVal = preorder[pre++];
        TreeNode* root = new TreeNode(rootVal);

        if(left == right)
            return root;

        int leftRoot = preorder[pre];
        int index = mp[leftRoot];
        root->left = build(preorder, postorder, mp,pre, left, index);
        root->right = build(preorder, postorder, mp,pre, index + 1, right - 1);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder,vector<int>& postorder) {

        unordered_map<int, int> mp;
        for(int i = 0; i < postorder.size(); i++) {
            mp[postorder[i]] = i;
        }
        int pre = 0;
        return build(preorder, postorder, mp,pre, 0, postorder.size() - 1);
    }
};