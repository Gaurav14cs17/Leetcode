
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();


        long long int p1 = nums[0]*nums[1];
        long long int p2 = nums[n-1]*nums[n-2];

        int ans = abs(p1 - p2);
        return ans;
    }
};