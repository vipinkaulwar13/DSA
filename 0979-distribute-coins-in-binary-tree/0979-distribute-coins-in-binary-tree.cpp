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
    int count = 0;
    int solve(TreeNode* root){
        if(root == nullptr) return 0;
        int left = solve(root->left), right = solve(root->right);
        count += abs(left) + abs(right);
        
        return root->val + left + right -1;
        
        
    }
    int distributeCoins(TreeNode* root) {
        
       solve(root);
        return count;
    }
};