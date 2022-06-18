/*
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
*/


class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans = 0 ;

        for(auto it : s ){
            if(st.empty()){
                st.push(it);
            }
            else if(!st.empty() && st.top() == '(' && it == ')'){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        return ans +  st.size();
    }
};