/*

https://leetcode.com/problems/counting-words-with-a-given-prefix/
*/


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0 , n = pref.length() ;
        for(auto s : words ){
            string s1 = s.substr(0, n );
            if(s1==pref)++ans;
        }
        return ans ;
    }
};