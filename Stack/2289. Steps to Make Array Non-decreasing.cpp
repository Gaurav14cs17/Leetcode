/*
https://leetcode.com/problems/steps-to-make-array-non-decreasing/
*/

class Solution {
public:
    int totalSteps(vector<int>& nums) {
       int n = nums.size();
        stack<int>st;
        vector<int>dp(n,0);
        for( int i = n-1 ; i>=0 ; --i){
            while(!st.empty()&& nums[i] > nums[st.top()]){
                dp[i] = dp[i] + 1;
                dp[i] = max( dp[i] , dp[st.top()]);
                st.pop();
            }
            st.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};