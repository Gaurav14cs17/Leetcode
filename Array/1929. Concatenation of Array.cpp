/*
https://leetcode.com/problems/concatenation-of-array/
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int>ans;
        for(auto x:nums)
            ans.push_back(x);

        for(auto x : nums )
            ans.push_back(x);

        return ans;
    }
};