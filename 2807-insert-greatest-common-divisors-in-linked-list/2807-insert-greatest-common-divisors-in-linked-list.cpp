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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        
        while(second){
            int value = __gcd(first->val, second->val);
            ListNode* temp = new ListNode(value);
            first->next = temp;
            temp->next = second;
            
            first = second;
            second = second->next;
        }
        return head;
    }
};