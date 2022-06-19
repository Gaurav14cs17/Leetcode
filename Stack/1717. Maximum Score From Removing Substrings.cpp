/*
https://leetcode.com/problems/maximum-score-from-removing-substrings/
*/


pair<string , int>find(string &s , string s1){
    int count = 0 ;
    stack<char>st;
    for( int i = 0  ; s[i] ; ++i ){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(st.top()==s1[0] && s[i]==s1[1]){
                count += 1;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return {ans , count};
}


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int value_1 = 0 , value_2 = 0;
        if(x > y ){
            auto it = find( s , "ab");
            value_1 += it.second*x;

            it = find(it.first , "ba");
            value_1 += it.second*y;
        }
        else{

            auto it = find( s , "ba");
            value_2 += it.second*y;

            it = find(it.first , "ab");
            value_2 += it.second*x;
        }

        return max( value_1 , value_2);
    }
};