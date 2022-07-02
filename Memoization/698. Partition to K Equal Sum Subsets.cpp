/*
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
*/

// using rec and bitmast
 const int N = 5e5 + 5;

 class Solution {
 public:

     int dp[N];

     bool solve( vector<int>& nums ,   int n , int sum , int mask , int k , int cur_sum ){

         if(sum == cur_sum ){
             k = k - 1;
             cur_sum  = 0;
         }
         if(sum < cur_sum   || k <0 )
             return dp[mask] = false;

         if(mask  == (1<<n)-1 ) // mask [111111111111111]
             return dp[mask] = (k==0) ;

         if(dp[mask] != -1 )
             return dp[mask];

         int ans = 0 ;
         for( int i = 0  ; i<n ; ++i ){
             if(mask & (1<<i )) // marked [000000000000100]
                 continue;
             ans =  ans || solve(nums , n , sum  , mask|(1<<i) , k , cur_sum +nums[i] ); // set bit mask[000000000000100]

         }

         return dp[mask] = ans;
     }

     bool canPartitionKSubsets(vector<int>& nums, int k) {
         int sum = 0 ;
         memset(dp , -1 , sizeof(dp));
         for(auto it : nums )
             sum += it;

         if(sum%k != 0 )
             return false;
         else
             sum = sum/k;

         return solve(nums , nums.size() , sum , 0 , k , 0  );
     }
 };
