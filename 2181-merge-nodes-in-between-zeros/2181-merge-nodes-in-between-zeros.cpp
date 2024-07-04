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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* fast = head;
        int cur = 0;
        vector<int>temp;
        while(fast != nullptr){
            if(fast->val == 0){
                temp.push_back(cur);
                cur = 0;
            }
            else{
                cur += fast->val;
            }
            fast = fast->next;
        }
        
        ListNode* head2 = new ListNode(temp[1]);
        ListNode* temp3 = head2;
        for(int i = 2; i<temp.size(); i++){
            ListNode* temp1 = new ListNode(temp[i]);
            temp3->next = temp1;
            temp3 = temp3->next;
        }
        return head2;
    }
};