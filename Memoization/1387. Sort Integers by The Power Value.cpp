/*
https://leetcode.com/problems/sort-integers-by-the-power-value/
*/

class Solution {
    int N = 5000005;
    int dp[5000005] = {-1};

    int solve(int n ){
        if(n==1)return 0 ;
        if(n &1 ) dp[n] = 1 + solve(3*n +  1 );
        else
            dp[n] = 1 + solve(n/2);
        return dp[n];
    }

public:
    int getKth(int lo, int hi, int k) {
          vector<pair<int, int>> array_val;
         for(int i=lo; i<=hi; i++)
            array_val.push_back({solve(i), i});

        sort(array_val.begin(), array_val.end());
        return array_val[k-1].second;
    }
};