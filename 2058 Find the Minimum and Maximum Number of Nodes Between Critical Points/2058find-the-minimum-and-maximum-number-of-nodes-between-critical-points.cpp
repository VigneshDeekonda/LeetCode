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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        int minDistance =INT_MAX;
        ListNode* curr = head->next;
        int currentposition = 1;
        int previoucritical = 0;
        int firstCritical = 0;

        while (curr->next != NULL) {
            if ((curr->val < prev->val && curr->val < curr->next->val) ||
                (curr->val > prev->val && curr->val > curr->next->val)) {
                if (previoucritical == 0) {
                    previoucritical = currentposition;
                    firstCritical = currentposition;
                } else {
                    minDistance = min(minDistance,currentposition - previoucritical );
                    previoucritical = currentposition;
                }
            }

            currentposition++;
            prev = curr;
            curr = curr->next;


        }
        if(minDistance == INT_MAX){
            return {-1,-1};
        }
        int maxDistance = previoucritical - firstCritical;
        return{minDistance,maxDistance};
    }
};