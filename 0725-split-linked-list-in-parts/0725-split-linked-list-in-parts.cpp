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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        vector<ListNode*>res;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        int x = len%k;
        int y = len/k;
        while(head){
            ListNode* temp = head;
            int size = y+(x-- >0?1:0);
            for(int i = 0; i<size-1; i++){
                head = head->next;
            }
            ListNode* nextn = head->next;
            head->next = nullptr;
            res.push_back(temp);
            head = nextn;
        }
        ListNode* temp2 = nullptr;
        if(res.size()<k){
            int siz = res.size();
            for(int i = 0; i<k-siz; i++){
                res.push_back(temp2);
            }
        }
        return res;
    }
};