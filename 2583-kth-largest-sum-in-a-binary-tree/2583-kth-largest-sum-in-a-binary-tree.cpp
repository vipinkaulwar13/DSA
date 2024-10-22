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
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>res;
        long long ans = 0;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            long long lev = 0;
            for(int i = 0; i<siz; i++){
                TreeNode* temp = q.front();
                q.pop();
                lev += (long long)temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(lev);
        }
        sort(res.begin(), res.end(), greater<long long>());
        if(k>res.size()) return -1;
        return res[k-1];
    }
};