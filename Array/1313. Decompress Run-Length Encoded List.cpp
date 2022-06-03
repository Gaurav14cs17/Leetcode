/*

1313. Decompress Run-Length Encoded List

*/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
       vector<int>ans;
       int n = nums.size();

       for(int i = 0 ; i<n ; i+=2 ){
           int f = nums[i];
           int val = nums[i +1];
           while(f--)
               ans.push_back(val);

           }
     return ans ;
    }
};