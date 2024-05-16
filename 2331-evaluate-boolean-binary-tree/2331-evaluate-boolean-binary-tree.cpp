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
// class Solution {
// public:
//     void solve(TreeNode* root, TreeNode* temp){
//         if(temp->left == nullptr && temp->right == nullptr) return;
//         if((temp->left->val == 1 || temp->left->val == 0) && (temp->right->val == 1 || temp->right->val == 0)){
//             if(temp->val == 2){
//                 temp->val = temp->left->val || temp->right->val;
//             }
//             else{
//                 temp->val = temp->left->val && temp->right->val;
//             }
//         }
//         else if(temp->left->val == 2 || temp->left->val == 3){
//             solve(temp->left, temp);
//         }
//         else solve(temp->right, temp);
    
//     }
//     bool evaluateTree(TreeNode* root) {
//         TreeNode *temp2 = root;
        
//         if(temp2->val == 1 || temp2->val == 0) return temp2->val;
        
//         solve(root, temp2);
        
//         return temp2->val;
        
//     }
// };


class Solution {
public:
  bool evaluateTree(TreeNode* root) {
    if (!root) return false;  

    if (root->val == 0) return false;
    if (root->val == 1) return true;

    
    bool left_result = evaluateTree(root->left);
    bool right_result = evaluateTree(root->right);

    if (root->val == 2) {
      return left_result || right_result;  
    } else {
      return left_result && right_result;  
    }
  }
};
