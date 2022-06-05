/*
https://leetcode.com/problems/find-greatest-common-divisor-of-array/
*/

class Solution {
public:
    const int N = 5e5 +5;
    int findGCD(vector<int>& nums) {
       int mn = N;
       int mx = -1 , n = nums.size();

       for(int i = 0  ; i<n ; ++i ){
           mn = min(mn , nums[i]);
           mx = max(mx , nums[i]);
       }
       return __gcd(mn , mx);
    }
};