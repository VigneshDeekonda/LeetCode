class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        int arr[5] = {0};

        for(int i=0;i<n;i++){
            char c = text[i];
            if(c == 'b')
                arr[0]++;
            else if(c == 'a')
                arr[1]++;
            else if(c == 'l')
                arr[2]++;
            else if(c == 'o')
                arr[3]++;
            else if(c == 'n')
                arr[4]++;
        }

        int minimum = INT_MAX;

        minimum = min(minimum,arr[0]);
        minimum = min(minimum,arr[1]);
        minimum = min(minimum,arr[2]/2);
        minimum = min(minimum,arr[3]/2);
        minimum = min(minimum,arr[4]);

        return minimum;
    }
};