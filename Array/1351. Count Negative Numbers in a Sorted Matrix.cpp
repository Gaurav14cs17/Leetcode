/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();

        for( int i = 0 ; i<n ; ++i ){
            for(int j = 0 ; j<grid[i].size() ; ++j ){
                if(grid[i][j]>=0)
                    continue;
                ans += 1;
            }

        }
        return ans ;
    }
};