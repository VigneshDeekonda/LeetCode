class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* previous =NULL;
        ListNode* Slowpointer = head;
        ListNode* Fastpointer = head;

        while(Fastpointer != NULL && Fastpointer->next != NULL){
            previous = Slowpointer;
            Slowpointer = Slowpointer->next;
            Fastpointer = Fastpointer->next->next;
        }
        previous->next = Slowpointer->next;
        delete(Slowpointer);

        return head;
    }
};