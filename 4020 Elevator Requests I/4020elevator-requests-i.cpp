class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
       int current = 0;
      int time = 0;

      for(int fl : requests ){
        time += abs(current - fl);
          current = fl;
      }
      return time;
    }
};