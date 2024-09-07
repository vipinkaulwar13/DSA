/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//     void lvlorder(TreeNode* root, vector<unordered_set<int>>& res){
//         queue<TreeNode*>q;
//         q.push(root);
     
//         while(!q.empty()){
//             int size = q.size();
//             unordered_set<int>level;
//             for(int i = 0; i<size; i++){
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 level.insert(temp->val);
//                 if(temp->left) q.push(temp->left);
//                 if(temp->right)q.push(temp->right);
//             }
//             res.push_back(level);
            
//         }
//     }
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         vector<unordered_set<int>>res;
//         lvlorder(root, res);
//         ListNode* temp = head;
        
//         for(int i = 0; i<res.size(); i++){
//             if(temp == nullptr) break;
//             if(res[i].contains(temp->val)) temp = temp->next;
            
//         }
//         return temp == nullptr?true:false;
//     }
// };

class Solution {
    bool isStartPath(ListNode* head, TreeNode* root) {
        if (head==nullptr) return true;
        if (root==nullptr) return false;
        return (head->val==root->val) && (isStartPath(head->next, root->left) || isStartPath(head->next, root->right));
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==nullptr)   return true;
        if(root==nullptr)   return false;
        return head->val==root->val && isStartPath(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};