/*
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
*/


// DP
const int N = 500;
int dp[N][N];
int solve(vector<int>&arr , int s , int n ){
    if(s==n)return dp[s][n] = 0;
    if(dp[s][n] != -1)
        return dp[s][n];
    int ans = INT_MAX;
    for( int i = s ; i<n ; ++i ){
        int left = solve( arr , s , i );
        int right = solve( arr , i + 1 , n);
        int mx_left = *max_element(arr.begin() + s , arr.begin() + i + 1 );
        int mx_right = *max_element(arr.begin() + i+1 , arr.begin() + n + 1);
        int value  = left + right + (mx_left*mx_right);
        ans = min( ans , value  );
    }
    return dp[s][n] = ans;
}


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
       memset(dp , -1 , sizeof dp);
       int ans  = solve(arr , 0 , arr.size()-1);
       return ans;
    }
};