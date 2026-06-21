class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        int mx = *max_element(costs.begin(), costs.end());

        vector<int> freq(mx + 1, 0);

        for (int cost : costs)
            freq[cost]++;

        int j = 0;
        for (int price = 1; price <= mx; price++) {
            while (freq[price] > 0) {
                costs[j++] = price;
                freq[price]--;
            }
        }

        int count = 0;
        int sum = 0;

        for (int cost : costs) {
            if (sum + cost <= coins) {
                sum += cost;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
};