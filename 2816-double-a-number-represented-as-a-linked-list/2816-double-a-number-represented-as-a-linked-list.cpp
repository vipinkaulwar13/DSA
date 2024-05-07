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
// class Solution {
// public:
//     int reverseDigits(int num) 
// { 
//     int rev_num = 0; 
//     while (num > 0) { 
//         rev_num = rev_num * 10 + num % 10; 
//         num = num / 10; 
//     } 
//     return rev_num; 
// } 
    
//     ListNode* doubleIt(ListNode* head) {
//         ListNode* temp1 = head;
//         ListNode* temp2 = head;
//         ListNode* temp3;
//         int num = head->val;
//         while(temp1->next != nullptr){
//             temp1 = temp1->next;
//             num *= 10;
//             num += temp1->val;
//         }
//         num = num*2;
        
//         int rev = reverseDigits(num);
//         while(temp2 != nullptr){
//             int a = rev%10;
//             rev = rev/10;
//             temp2->val = a;
//             temp3 = temp2;
//             temp2 = temp2->next;
//         }
//         if(rev == 0) return head;
        
//         else{
//             while(rev){
//                 int a = rev%10;
//                 rev = rev/10;
//                 ListNode* newnode = new ListNode(a);
//                 temp3->next = newnode;
//                 temp3 = temp3->next;
//             }
//         }
//         return head;
//     }
// };

// class Solution {
// public:

//     ListNode* doubleIt(ListNode* head) {
//         ListNode* temp1 = head;
//         ListNode* temp2 = head;
//         ListNode* temp3;
//         int num = head->val;
//         while(temp1->next != nullptr){
//             temp1 = temp1->next;
//             num *= 10;
//             num += temp1->val;
//         }
//         num = num*2;
//         stack<int>st;
//         while(num){
//             int a = num%10;
//             st.push(a);
//             num = num/10;
//         }
//         while(temp2 != nullptr){
        
//             temp2->val = st.top();
//             st.pop();
//             temp3 = temp2;
//             temp2 = temp2->next;
//         }
//         if(st.empty()) return head;
        
//         else{
//             while(!st.empty()){
//                 ListNode* newnode = new ListNode(st.top());
//                 temp3->next = newnode;
//                 temp3 = temp3->next;
//             }
//         }
//         return head;
//     }
// };

class Solution{
    public:
    ListNode* doubleIt(ListNode* head){
        if(head->val >4){
            head = new ListNode(0, head);
        }
        ListNode* curr = head;
        while(curr){
            curr->val = curr->val*2 %10;
            if(curr->next && curr->next->val>4){
                curr->val++;
            }
            curr = curr->next;
        }
        return head;
    }
};
