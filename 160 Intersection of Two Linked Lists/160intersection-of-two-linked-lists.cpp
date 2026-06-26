/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2) return temp1;

            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
         }
         return temp1;
    }
};



//moving the temp1 and temp2 simulataneousely so that after any one of them reaching the NULL so they will switch to next(different or opposite head) and start moving and whenever the temp1 and temp2 meets that will be the intersection of any 2 different linkedlist connected to each other with one point 