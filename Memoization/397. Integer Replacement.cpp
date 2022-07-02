/*
https://leetcode.com/problems/integer-replacement/
*/


class Solution {
public:


    int solve( long long int n ,   unordered_map<long long int  , long long int  >&dp ){

        if(n==1)
            return dp[n] = 1LL*0 ;

         if(dp.find(n) != dp.end())
             return dp[n];


        int ans ;
        if(n&1)
            ans = 1 + 1LL*min( solve(n-1 , dp ) , solve(n+1, dp ));
        else
            ans =  1LL + 1LL*solve(n/2 , dp );

        return dp[n] = 1LL*ans;
    }
    int integerReplacement(int n) {
         unordered_map<long long int  , long long int  >dp;
        return solve(1LL*n , dp );
    }
};