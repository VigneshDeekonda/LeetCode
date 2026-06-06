// class Solution {
// public:
//     bool consecutiveSetBits(int n) {
//         int count = 0;
//       while(n>1){
//         if((n&1) && ((n>>1) & 1))
//           count++;

//         if(count>1)
//           return false;

//         n >>= 1;
//       }
//       return count ==1;
//     }
// };

class Solution {
public:
    bool consecutiveSetBits(int n) {
      int x = n & (n>>1);

      return x && ((x &(x-1))==0);
    }
};