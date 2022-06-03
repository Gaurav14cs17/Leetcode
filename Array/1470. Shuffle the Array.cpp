/*
https://leetcode.com/problems/shuffle-the-array/
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int>ans;
        int l_1 = 0;
        int l_2 = n;
        while(l_1 <n && l_2<2*n ){
            ans.push_back(nums[l_1]);
            ans.push_back(nums[l_2]);
            l_1 += 1;
            l_2 += 1;
        }
        return ans ;
    }
};