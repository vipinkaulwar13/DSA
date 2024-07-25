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
public:
    int solve(TreeNode* root, int& mpath){
        if(!root) return 0;
        
        int left = max(0,solve(root->left, mpath));
        int right = max(0,solve(root->right, mpath));
        mpath = max(mpath, left+right+root->val);
        
        return (root->val)+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int mpath = INT_MIN;
        solve(root, mpath);
        return mpath;
    }
};