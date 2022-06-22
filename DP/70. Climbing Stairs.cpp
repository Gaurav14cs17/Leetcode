/*
https://leetcode.com/problems/climbing-stairs/
*/
const int N = 5e5;
int dp[N];
int solve( int n , int &cnt ){
    if(n==0 || n==1 ){
        cnt += 1;
        return dp[n] = 1;
    }
    if(n<0 )
        return dp[n] = 0;

    if(dp[n] != -1 )
        return dp[n];

    return dp[n] = solve(n-1 , cnt ) + solve(n-2 , cnt );
}

class Solution {
public:
    int climbStairs(int n) {
    int cnt =  0;
    memset(dp , -1 , sizeof(dp));
    int ans = solve(n , cnt );
    cout<<cnt;
    return ans;
    }
};