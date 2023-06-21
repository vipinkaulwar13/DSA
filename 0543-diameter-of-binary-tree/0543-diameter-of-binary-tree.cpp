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
    int ans = 0;
    int maxheight(TreeNode* root){
        if(!root) return {};
        
        int maxleft = maxheight(root->left);
        int maxright = maxheight(root->right);
        ans = max(ans, 1+maxleft+maxright);
        return max(maxleft, maxright)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxheight(root);
        return ans-1;
    }
};