/*
https://leetcode.com/problems/baseball-game/
*/


class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;

        for(auto it : ops ){
            if(it == "C" && !st.empty()){
                st.pop();
            }
            else if(it =="+" && st.size()>=2 ){
                int value = st.top();
                st.pop();
                int x = value + st.top();
                st.push(value);
                st.push(x);
            }
            else if(it == "D" && !st.empty()){
                st.push(2*st.top());
            }
            else{
                int x = 0;
                x = atoi(it.c_str());
                st.push(x);
            }
        }
      int  ans =  0;
      while(!st.empty()){
          ans += st.top();
          st.pop();
      }
      return ans;
    }
};