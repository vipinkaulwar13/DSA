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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
	unordered_map<int, int> ans; unordered_map<TreeNode*, int> hts; vector<int> res;
	function<int(TreeNode*)> height = [&](TreeNode* r) {
		return r ? (hts[r] = 1 + max(height(r->left), height(r->right))) : 0; 
	};
	function<void(TreeNode*,int,int)> dfs = [&](TreeNode* r, int depth, int mx) {
		if (!r) return;
		ans[r->val] = mx;
		dfs(r->right, depth + 1, max(mx, depth + hts[r->left]));
		dfs(r->left, depth + 1, max(mx, depth + hts[r->right]));
	};
	height(root); dfs(root, 0, 0);
	for (int& v: queries) res.push_back(ans[v]);
	return res;
}
};