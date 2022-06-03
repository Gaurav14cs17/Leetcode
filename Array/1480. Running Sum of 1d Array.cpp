/*
https://leetcode.com/problems/running-sum-of-1d-array/
*/




class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        vector<int>ans(n);
        ans[0] = nums[0];
        //ans.push_back(nums[0]);

        for(int i =1  ; i<n ; ++i ){
            ans[i] = ans[i-1] + nums[i];
            //ans.push_back(dp[i]);
        }
        return ans ;
    }
};