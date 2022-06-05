/*
https://leetcode.com/problems/find-the-highest-altitude/
*/

class Solution {
public:
    const int N = 5e5 +5;
    int largestAltitude(vector<int>& gain) {
        int dp[N];
        int n = gain.size();
        dp[0] = 0;
        int mx = 0;
        for(int i = 1 ;i<=n ; ++i  ){
            dp[i] = dp[i-1] + gain[i-1];
            mx =  max(mx , dp[i]);
        }
        return mx;
    }
};