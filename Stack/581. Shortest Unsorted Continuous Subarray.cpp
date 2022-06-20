/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v = nums;
        int l = 0;
        int r = n-1;
        sort(v.begin() , v.end());
        while(l < r ){
            if(v[l]==nums[l]){
                ++l;
            }
            else if(v[r] == nums[r]){
                --r;
            }
            else {
                break;
            }
        }
        if( r > l )
            return r- l +1;
        return 0;
    }
};