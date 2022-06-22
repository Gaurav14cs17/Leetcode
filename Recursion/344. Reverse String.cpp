/*

https://leetcode.com/problems/reverse-string/

*/

class Solution {
    void solve(vector<char>&s, vector<char>&ans ,int idx , int n ){
        if(idx == n )
            return ;
        solve( s , ans ,idx + 1 , n );
        ans.push_back(s[idx]);

    }
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char>ans;
        solve( s , ans , 0 , n );
        s = ans ;

    }
};