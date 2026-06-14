// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//       vector<int> vec;
//       ListNode* curr = head;

//       while(curr!= NULL){
//         vec.push_back(curr->val);
//         curr = curr->next;
//       }
//       int result = 0;
//       int i = 0;
//       int j = vec.size()-1;
//       while(i<j){
//         result = max(result,vec[i]+vec[j]);
//         i++;
//         j--;
//       }
//       return result;
//     }
// };


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* mid = NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        
        //Reversing Part
        ListNode* nextNode = NULL;
        ListNode* prev = NULL;
        while(mid) {
            nextNode = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nextNode;
        }

        ListNode* curr = head;
        int result = 0;
        while(prev) {
            result = max(result, curr->val + prev->val);
            curr = curr->next;
            prev = prev->next;
        }
        
        return result;
        
    }
};