/*
https://leetcode.com/problems/richest-customer-wealth/

*/class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int mx = 0;
        int col = accounts[0].size();
        int row = accounts.size();

        for(int r = 0 ; r<row ; ++r ){
            int ans = 0;
            for(int c = 0  ; c< col ; ++c)
                ans += accounts[r][c];

            mx = max(mx , ans);
        }
        return mx;
    }
};