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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m, vector<int>(n, -1));
        int x = 0, y = 0;
        while(head){
            
            for(int i = y; i<n&&head; i++){
                res[x][i] = head->val;
                head = head->next;
            }
            x++;
            for(int j = x; j<m&&head; j++){
                res[j][n-1] = head->val;
                head = head->next;
            }
            n--;
            if(x<m){
                for(int i = n-1; i>=y&&head; i--){
                    res[m-1][i] = head->val;
                    head = head->next;
                }
                m--;
            }
            if(y<n){
                for(int j = m-1; j>=x&&head; j--){
                    res[j][y] = head->val;
                    head = head->next;
                }
                y++;
            }
            
        }
        return res;
    }
};