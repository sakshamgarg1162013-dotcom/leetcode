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
    bool ismirror(TreeNode* n1, TreeNode* n2){
        if(n1 ==NULL && n2==NULL){
            return true;
        }
        if((n1==NULL && n2!=NULL) || (n1!=NULL && n2==NULL) || (n1->val!=n2->val)){
            return false;
        }
        bool ans1 = ismirror(n1->left,n2->right);
        bool ans2 = ismirror(n1->right,n2->left);

        return ans1 && ans2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        int ans = ismirror(root->left,root->right);
        return ans;
    }
};