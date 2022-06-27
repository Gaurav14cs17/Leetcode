/*
https://leetcode.com/problems/predict-the-winner/
soln :  https://leetcode.com/problems/predict-the-winner/discuss/2206053/Game-theory-(-uploaded-diagram-of-recursion-)
*/



class Solution {
public:

    // Method_1
    int solve( vector<int>&nums , int s_idx , int e_idx   ){
      if( s_idx > e_idx )
          return 0;

      // for player_1 , check image
      int c_0 = nums[s_idx] + min(solve( nums , s_idx + 2 , e_idx ) , solve( nums , s_idx + 1  , e_idx - 1 ) );
      int c_1 = nums[e_idx] + min(solve( nums , s_idx , e_idx - 2 ) , solve( nums , s_idx + 1  , e_idx - 1 ) );

     return max( c_0 , c_1 );
    }

    // Method 2

    int dp[30][30][2];

    int solve_2( vector<int>&nums , int i , int n , int player){
        if( i > n ) return 0;

        int ans = 0 ;
        if(dp[i][n][player] != -1 )
            return dp[i][n][player];

        if(player){
             int c_0 = nums[i] + solve_2( nums , i + 1  , n , player ^1 );
             int c_1 = nums[n] + solve_2( nums , i  , n - 1 , player ^1 );
             ans =  max( c_0 , c_1 );

        }
        else{
             int c_0 = nums[i]*(-1) + solve_2( nums , i + 1  , n , player ^1 );
             int c_1 = nums[n]*(-1) + solve_2( nums , i  , n - 1 , player ^1 );
             ans =  min( c_0 , c_1 );
        }

        return dp[i][n][player] = ans ;


    }

    bool PredictTheWinner(vector<int>& nums) {
       int n = nums.size()-1;


       memset( dp , -1 , sizeof(dp));
       int ans = solve_2( nums , 0  , n , 1 );
       if( ans >=0 )
           return 1;
       else
           return 0 ;


    }
};