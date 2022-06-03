/*

https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

*/

class Solution {
public:
    const int N = 4e3 + 5;


   int countKDifference(vector<int>& nums, int k) {
        int  cnt = 0;
        int  n = nums.size();
        unordered_map<int,int>dp;

        for(int i=0 ; i<n ; ++i){
         cnt += dp[nums[i]-k] + dp[nums[i] + k]  ;
         dp[nums[i]] += 1;
        }




        return cnt;
    }
};