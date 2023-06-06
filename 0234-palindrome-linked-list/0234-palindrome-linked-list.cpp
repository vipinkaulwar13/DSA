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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!= nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr && fast->next == nullptr){
            slow = slow->next;
        }
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        while(slow!= nullptr && slow->next != nullptr){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
            
        }
        if(slow!= NULL){
            slow->next = prev;
        }
        fast = head;
        while(fast && slow){
            if(fast->val!=slow->val){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
