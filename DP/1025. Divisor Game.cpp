/*
https://leetcode.com/problems/divisor-game/
*/


const int N = 10000;
int dp[N][N];

int solve( int n , int k , int f = 1 ){

     if(n==0 || k==0)
         return dp[n][k] = f;

     if(dp[n][k] != -1 )
         return dp[n][k];

     if(n % k ==0 )
         f = solve( n-k , k , 1^f );
     else
         f = solve( n , k-1 , f);

    return dp[n][k]=f;
    return f;
}

class Solution {
public:


    bool divisorGame(int n) {
        if(n==1)
            return false;

        memset( dp , -1 , sizeof(dp));
        if(solve( n , n-1 , 1 ))
            return true;
        return false;
    }
};