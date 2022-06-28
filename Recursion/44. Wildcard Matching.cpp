/*
https://leetcode.com/problems/wildcard-matching/
*/


int dp[2005][2005];

int solve( int i , int j , string &s , string &p ){

    if(i<0 && j < 0  )
        return 1;

     else if( i < 0 && j>=0){
         for(int k=0; k<=j; k++) if(p[k]!='*')
            return 0 ;
         return  1;
     }

    else if( i>=0 && j< 0 )
        return 0;

    if(dp[i][j] != -1 )
        return dp[i][j];

    int  res = 0 ;
    if(s[i]== p[j] || p[j]=='?')
        return dp[i][j] =  solve( i-1 , j-1 , s , p );

    if(p[j]=='*') {
            bool op_1 = solve( i -1 , j-1 , s , p );
            bool op_2 = solve(i-1 , j , s , p );
            bool op_3 = solve(i , j-1 , s , p );
            res =  op_1 || op_2 || op_3;
    }
    return dp[i][j] =  res ;
}


class Solution {
public:
    bool isMatch(string s, string p) {
       int n = s.length()-1;
       int m = p.length()-1;
        memset(dp , -1 , sizeof(dp));
       return solve( n , m , s , p );
    }
};