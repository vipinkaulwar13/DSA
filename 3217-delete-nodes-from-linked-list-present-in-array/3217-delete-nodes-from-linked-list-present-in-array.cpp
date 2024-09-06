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
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         unordered_map<int,pair<int,int>>mp;
//         ListNode* temp = head;
//         while(temp){
//             mp[temp->val].first++;
//             mp[temp->val].second++;
//             temp = temp->next;
//         }
        
//         for(int i = 0; i<nums.size(); i++){
//             if(mp.find(nums[i])!=mp.end()){
//                 mp[nums[i]].first = 0;
//             }
//         }
//         for(auto& pair:mp){
//             if(pair.second.first == 0){
//                 ListNode* temp = NULL;
//                 ListNode* temp2 = head;
//                 while(pair.second.second){
//                     if(pair.first == head->val){
//                         head = head->next;
//                         temp = temp2;
//                         temp2 = temp2->next;
//                         pair.second.second--;
//                     }
//                     else if(pair.first == temp2->val && temp2->next == nullptr){
//                         temp->next = nullptr;
//                         pair.second.second--;
//                     }
//                     else if(pair.first == temp2->val){
//                         temp2 = temp2->next;
//                         temp->next = temp2;
//                         pair.second.second--;
//                     }
//                     else{
//                         temp = temp2;
//                         temp2 = temp2->next;
//                     }
//                 }
//             }
//         }
//         return head;
        
//     }
// };
class Solution {
    public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode tmp(0, head);
        unordered_set<int> s(begin(nums), end(nums));
        for (auto *p = &tmp; p->next != nullptr; )
            if (s.contains(p->next->val))
                p->next = p->next->next;
            else
                p = p->next;
        return tmp.next;
    }
};