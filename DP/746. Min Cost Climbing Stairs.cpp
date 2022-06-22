/*

https://leetcode.com/problems/min-cost-climbing-stairs/

*/

int solve( int n , vector<int>&cost , int dp_array[] ){
    if(dp_array[n] != -1 )
        return dp_array[n];

    if(n == 0 || n== 1)
        return dp_array[n] = cost[n];

    int one_step = solve(n-1 , cost , dp_array );
    int two_step = solve(n-2 , cost , dp_array );

    int mn_value = cost[n] + min(one_step , two_step );
    return dp_array[n] = mn_value;
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        // int dp_array[10001];
        // memset( dp_array , -1 , sizeof(dp_array));
        int n = cost.size();
        // return solve(n-1 , cost , dp_array );
        int dp[n+1];
        dp[0] = 0;
        dp[0] = cost[0];
        dp[1] = cost[1];


        for( int i =  2 ; i< n  ; ++i )
            dp[i] = min(dp[i-1]+ cost[i] , dp[i-2] + cost[i]);

        return dp[n-1];
    }
};