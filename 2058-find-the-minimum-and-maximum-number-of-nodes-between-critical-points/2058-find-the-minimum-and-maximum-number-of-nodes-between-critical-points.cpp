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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2, -1);
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* ncxt = head->next->next;
        
        //int temp = 0, minn = INT_MAX;
        int count = 1;
        vector<int> res;
        
        while(curr->next != nullptr){
            if((prev->val<curr->val && ncxt->val<curr->val) || (prev->val>curr->val && ncxt->val>curr->val)){
                res.push_back(count);
                // minn = min(minn, count-temp);
                // temp = count;
                
            }
            prev = curr;
            curr = ncxt;
            ncxt = ncxt->next;
            count++;
        }
        
        if(res.size()<2) return ans;
        int Max = res[res.size()-1]-res[0];
        
        int Min = INT_MAX;
        
        for(int i = 0; i<res.size()-1; i++){
            int temp = res[i+1]-res[i];
            Min = min(Min, temp);
        }
        ans[0] = Min;
        ans[1] = Max;
        
        return ans;
        
    }
};