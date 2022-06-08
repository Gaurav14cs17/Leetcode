/*
https://leetcode.com/problems/make-the-string-great/
*/

class Solution {
public:
    bool check(char s1, char s2 ){
        if(s1 == s2 )
            return true;
        else if( s1 == char(s2^32) )
            return true;
        else if(char(s1^32) == s2)
            return true;

        return false;

    }

    string makeGood(string s) {
        stack<char>st;
        for( int i = 0  ; i<s.length() ; ++i ){
           if(st.empty() || abs(s[i] - st.top())!= 32 ){
               st.push(s[i]);
           }
           else{
               st.pop();
           }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};