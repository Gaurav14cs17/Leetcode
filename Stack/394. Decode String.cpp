/*
https://leetcode.com/problems/decode-string/
*/

class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        unordered_map<int,int> mp;
        st.push("");
        int total = 0 ;
        for( int i = 0  ; s[i] ; ++i ){
            if(isdigit(s[i])){
                total = total*10;
                total = total + (s[i]-'0');
            }
            else if(s[i]=='['){
                st.push("");
                mp[st.size()] = total;
                total = 0 ;
            }
            else if(s[i]==']'){
                string s2 = "";
                int x = mp[st.size()];
                while(x){
                    s2 = s2 + st.top();
                    x = x-1;
                }
                st.pop();
                st.top() += s2;
            }
            else{
                st.top() = st.top() + s[i] ;
            }
        }
        return st.top() ;
    }
};