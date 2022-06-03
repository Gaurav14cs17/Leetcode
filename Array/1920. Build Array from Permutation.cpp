/*

https://leetcode.com/problems/build-array-from-permutation/
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        vector<int> ans;

        for( int i = 0  ; i<n ; ++i ){
            dp[i] = nums[i];
        }

      for( int i = 0  ; i<n ; ++i ){
            ans.push_back(nums[dp[i]]);
        }

        return ans ;

    }
};