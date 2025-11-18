class Solution {
public:

//funtion for left max array and right max array
        vector<int> getleftmaxArray(vector<int> &height,int &n){
            vector<int> Leftmax(n);
          Leftmax[0] = height[0];
          for(int i=1;i<n;i++){
             Leftmax[i] = max(Leftmax[i-1],height[i]);
          }
        return Leftmax;
        }

// funcion for right max for array
        vector<int> getrightmaxArray(vector<int> &height,int &n){
            vector<int> Rightmax(n);
          Rightmax[n-1] = height[n-1];  
           for(int i=n-2;i>=0;i--){
             Rightmax[i] = max(Rightmax[i+1],height[i]);
          }
        return Rightmax;
        }
        

//main function
    int trap(vector<int>& height) {
         int n = height.size();
         vector<int> Leftmax = getleftmaxArray(height,n);
         vector<int> Rightmax = getrightmaxArray(height,n);
          int sum = 0;
          for(int i = 0;i<n;i++){
          int h = min(Leftmax[i], Rightmax[i]) - height[i];
          sum = sum + h; 
          }
        return sum;
    }
};