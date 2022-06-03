/*
https://leetcode.com/problems/create-target-array-in-the-given-order/
*/



class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int>ans;

        for(int i =0 ; i<n ;++i){
            int idx = index[i];
            int val = nums[i];
            ans.insert(ans.begin() + idx , val );
        }
        return ans ;
    }
};