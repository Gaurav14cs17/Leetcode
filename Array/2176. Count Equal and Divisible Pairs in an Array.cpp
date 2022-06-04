/*

https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/

*/




class Solution {
public:
    const int N =  5e5 +5;
    int countPairs(vector<int>& nums, int k) {




       int n = nums.size();
       int ans = 0;

       unordered_map<int , vector<int>>mp;

       for(int i = 0  ; i<n ; ++i ){

          if(mp.find(nums[i]) != mp.end()){
             for(auto it : mp[nums[i]])
                if((i*it)%k ==0 ) ++ans;
          }

           mp[nums[i]].push_back(i);
       }
       return ans;




    }
};