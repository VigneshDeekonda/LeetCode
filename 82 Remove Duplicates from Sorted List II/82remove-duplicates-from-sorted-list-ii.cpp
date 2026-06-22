class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        vector<int> arr;

        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> uniqueVals;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            int cnt = 1;

            while(i + 1 < n && arr[i] == arr[i + 1]){
                cnt++;
                i++;
            }

            if(cnt == 1)
                uniqueVals.push_back(arr[i]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int x : uniqueVals){
            tail->next = new ListNode(x);
            tail = tail->next;
        }

        return dummy->next;
    }
};