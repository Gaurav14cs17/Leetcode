/*
https://leetcode.com/problems/n-th-tribonacci-number/
*/

const int N = 5e5 +5;
int dp[N];

int solve(int n) {
    if( n == 0 || n == 1 || n == 2){
        if(n==0) return dp[n] =  0;
        else return dp[n] = 1;
    }
    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = solve(n-3) + solve(n-2) + solve(n-1);
}

class Solution {
public:
    int tribonacci(int n) {
        memset(dp , -1 , sizeof(dp));
        return solve(n);
    }
};