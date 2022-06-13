/*

https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/


class Solution {
public:
    const int N = 27;
    string smallestSubsequence(string s) {
        int n = s.length();
        map<int , int >mp;
        int vis[N];
        stack<char>st;

        for( int i = 0  ; i<n ; ++i )
            vis[s[i]-'a'] = i;

        for( int i = 0  ; i<n ; ++i ){
            if(mp[s[i]])
                continue;

            while(!st.empty() && st.top()>s[i] && vis[st.top()-'a']>i){
                mp[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
            mp[s[i]]++;
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};