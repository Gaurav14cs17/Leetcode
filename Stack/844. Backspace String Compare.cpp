/*

https://leetcode.com/problems/backspace-string-compare/
*/


class Solution {
public:
    string get_string(string s){
        stack<char>st;
        for(int i = 0  ; i<s.length() ; ++i ){
            if(s[i]=='#' and !st.empty())
                st.pop();
            else
                st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()){
            if(st.top() != '#')
                ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans ;
    }


    bool backspaceCompare(string s, string t) {
        string s1 = get_string(s);
        string s2 = get_string(t);
        //cout<<s1<<" "<<s2;

        return (s1==s2);
    }
};