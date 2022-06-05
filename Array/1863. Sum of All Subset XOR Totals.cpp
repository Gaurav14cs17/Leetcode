/*
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans =0;

        for(int bits =0 ; bits <(1<<n) ; ++bits ){
            int s =0;
            for(int i =0 ; i<n ; ++i ){
                if(bits&(1<<i))
                    s = s ^ nums[i];
            }
            ans += s;
        }
        return ans;
    }
};