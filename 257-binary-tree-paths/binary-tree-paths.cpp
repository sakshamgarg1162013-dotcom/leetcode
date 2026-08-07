/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void paths(vector<string> &ans, TreeNode* root, string &s) {

        if (root == NULL)
            return;

        int len = s.length();

        s += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
        }
        else {
            s += "->";

            paths(ans, root->left, s);
            paths(ans, root->right, s);
        }

        s.erase(len);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans;
        string s;

        paths(ans, root, s);

        return ans;
    }
};