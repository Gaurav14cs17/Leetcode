/*
https://leetcode.com/problems/sum-of-unique-elements/
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int , int >mp;
        int n = nums.size();

        for(int i = 0  ; i<n ; ++i )
            mp[nums[i]] += 1;

        int ans = 0;
        for(auto it : mp){
            if(it.second == 1)
                ans += it.first;
        }
        return ans;
    }
};

