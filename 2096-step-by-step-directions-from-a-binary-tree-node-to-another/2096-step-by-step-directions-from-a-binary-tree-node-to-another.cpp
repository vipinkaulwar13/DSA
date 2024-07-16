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
    
//     TreeNode* lcs(TreeNode* root, int startValue, int destValue){
//         if(root == NULL || root == startValue || root == destValue){
//             return root;
//         }
//         TreeNode* left = lcs(root->left, startValue, destValue);
//         TreeNode* right = lcs(root->right, startValue, destValue);
        
//         if(left == NULL) return right;
        
//         else if(right == NULL) return left;
        
//         else return root;
//     }
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         string res = "";
//         int curr = startValue;
        
//         //TreeNode* temp = lcs(root, startValue, destValue);
        
        
        
//     }
    
    bool find(TreeNode* n, int val, string &path) {
    if (n->val == val)
        return true;
    if (n->left && find(n->left, val, path))
        path.push_back('L');
    else if (n->right && find(n->right, val, path))
        path.push_back('R');
    return !path.empty();
}
string getDirections(TreeNode* root, int startValue, int destValue) {
    string s_p, d_p;
    find(root, startValue, s_p);
    find(root, destValue, d_p);
    while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
        s_p.pop_back();
        d_p.pop_back();
    }
    return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
}
};