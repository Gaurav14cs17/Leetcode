/*

https://leetcode.com/problems/keep-multiplying-found-values-by-two/
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
      int ans = original;
      while(find(nums.begin() , nums.end() ,ans) != nums.end()){
          ans = ans*2;
      }
      return ans;
    }
};