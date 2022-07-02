/*
https://leetcode.com/problems/word-break/
*/

class Solution {
public:

    bool solve( string &s , unordered_set<string>&wd , int idx  , vector<int>&dp ){
        if(idx == s.length())
            return true;

        if(dp[idx] != -1 )
            return dp[idx];

        string s_1;
        for( int i =  idx ; i<s.length() ; ++i ){
            s_1.push_back(s[i]);
            if( wd.find(s_1) == wd.end())
                continue;
            if(solve( s , wd , i + 1 , dp   ))
                return dp[idx] = true;


        }
        return  dp[idx] =false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wd;
        for(auto it : wordDict )
            wd.insert(it);
        int n = s.length();
        vector<int>dp( n , -1 );
        return solve( s , wd , 0 , dp  );

    }
};