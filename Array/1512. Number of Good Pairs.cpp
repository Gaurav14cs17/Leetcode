/*
https://leetcode.com/problems/number-of-good-pairs/

*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int cnt = 0;
        for( int i = 0 ; i<nums.size();++i){
            for(int j = i+1 ; j<nums.size();++j)
                if(i<j && nums[i]==nums[j])
                    cnt+=1;
        }
        return cnt ;
    }
};