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
    ListNode* reverselinkedlist(ListNode* head){
      if(head == NULL || head->next == NULL){
        return head;
      }
      ListNode* last = reverselinkedlist(head->next);
      head->next->next = head;
      head->next = NULL;
      return last;
    }
    ListNode* doubleIt(ListNode* head) {
      head = reverselinkedlist(head);
      ListNode* curr = head;
      ListNode* prev = NULL;
      int carry = 0;
      while(curr != NULL){
        int newvalue = curr->val*2 + carry;
        curr -> val = newvalue%10;

        if(newvalue >= 10){
          carry = 1;
        } else {
          carry = 0;
        }
        prev = curr;
        curr = curr->next;
      }
      if(carry!=0){
        ListNode* newhead = new ListNode(carry);
        prev ->next = newhead;
      }
      return reverselinkedlist(head);
    }
};