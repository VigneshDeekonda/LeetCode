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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* P1 = NULL;
        ListNode* P2 = NULL;
        ListNode* temp = head;
        while (temp != NULL) {

          if(P2 != NULL){
            P2 = P2->next;
          }
            k--;
            if (k == 0) {
                P1 = temp;
                P2 = head;
            }
            temp = temp->next;
        }
        swap(P1->val,P2->val);
        return head;
    }
};