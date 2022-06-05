/*
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/

Soln 1:

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


Soln : 2


class Solution {
public:

    void solve(vector<int>&nums , int idx  ,int n , int val , int &cur  ){

        if(idx==n){
            cur += val;
            return ;
        }

        solve( nums , idx +1 , n , val ^ nums[idx]  , cur );
        solve( nums , idx +1 , n , val , cur );
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        solve( nums , 0 , n , 0 , ans);
        return ans;
    }
};