/*

https://leetcode.com/problems/matrix-diagonal-sum/
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int k = mat.size();
        int n = 0 , m = 0;
        int ans = 0 ;
        while(n < k && m < k){
            ans += mat[n++][m++];
        }



        n = 0 , m = k;
        while(n <k && m ){
            ans += mat[n++][--m];
        }

        if(k&1){
            k = int(k/2) +1;
            ans -= mat[k-1][k-1];
        }

        return ans ;
    }
};