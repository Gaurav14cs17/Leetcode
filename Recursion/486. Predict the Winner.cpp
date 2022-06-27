/*
https://leetcode.com/problems/predict-the-winner/
*/


class Solution {
public:
    int solve( vector<int>&nums , int s_idx , int e_idx   ){
      if( s_idx > e_idx )
          return 0;

      // for player_1 , check image
      int c_0 = nums[s_idx] + min(solve( nums , s_idx + 2 , e_idx ) , solve( nums , s_idx + 1  , e_idx - 1 ) );
      int c_1 = nums[e_idx] + min(solve( nums , s_idx , e_idx - 2 ) , solve( nums , s_idx + 1  , e_idx - 1 ) );

     return max( c_0 , c_1 );
    }


    bool PredictTheWinner(vector<int>& nums) {
       int n = nums.size()-1;
       int ans = 0 ;
       int total = 0;
       for( auto it : nums)
           total += it;

       int player_1_value = solve( nums , 0 , n );
       int player_2_value = total - player_1_value;

       if(player_1_value >= player_2_value )
           return true;
        else
            return false;


    }
};