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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* previous =NULL;
        ListNode* Slowpointer = head;
        ListNode* Fastpointer = head;

        while(Fastpointer != NULL && Fastpointer->next != NULL){
            previous = Slowpointer;
            Slowpointer = Slowpointer->next;
            Fastpointer = Fastpointer->next->next;
        }
        return Slowpointer;
    }
};