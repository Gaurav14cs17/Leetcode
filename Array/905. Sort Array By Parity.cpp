/*

https://leetcode.com/problems/sort-array-by-parity/

*/


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       vector<int>ans;
       int n = nums.size();

       for(int i = 0  ; i<n ; ++i ){
           if(nums[i]&1)
               continue;
           ans.push_back(nums[i]);
           nums[i] = -1;
       }

       for(int i = 0  ; i<n ; ++i ){
           if(nums[i] != -1)
               ans.push_back(nums[i]);
       }

        return ans;
    }
};