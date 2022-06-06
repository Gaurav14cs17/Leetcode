/*
https://leetcode.com/problems/divide-array-into-equal-pairs/
*/


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int , int >mp;
        for(auto it : nums)
            mp[it] += 1;

        for(auto it : mp){
            if(it.second &1)
                return false;
        }

        return true;
    }
};