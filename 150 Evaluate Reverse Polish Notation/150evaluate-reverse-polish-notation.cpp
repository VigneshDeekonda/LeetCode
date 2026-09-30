// class Solution {
// public:
//     int Operation(int a, int b, string token) {
//         if (token == "+")
//             return a + b;
//         if (token == "-")
//             return a - b;
//         if (token == "/")
//             return a / b;
//         if (token == "*")
//             return (long)a * (long)b;

//           return -1;
//     }
//     int evalRPN(vector<string>& tokens) {
//         stack<int> st;

//         for (string& token : tokens) {
//             if (token == "+" || token == "-" || token == "*" || token == "/") {
//                 // take 2 values from the stack and pop them and store again
//                 // them into the stack
//                 int b = st.top();
//                 st.pop();
//                 int a = st.top();
//                 st.pop();
//                 int result = Operation(a, b, token);
//                 st.push(result);
//             } else {
//                 st.push(stoi(token));
//             }
//         }
//         return st.top();
//     }
// };


//using lambda funtion 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      //lamba funtion 
      unordered_map<string, function <int(int,int)> > mp = {
        {"+",[](int a,int b) 
            {return a+b;}},
        {"-",[](int a,int b) 
            {return a-b;}},
        {"/",[](int a,int b) 
            {return a/b;}},
        {"*",[](int a,int b) 
            {return (long)a*(long)b;}},
      };
        stack<int> st;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // take 2 values from the stack and pop them and store again
                // them into the stack
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int result =mp[token](a,b);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};


