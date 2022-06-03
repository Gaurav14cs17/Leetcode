/*
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp_array(n);
        vector<int>ans;
        for(int i = 0 ; i<n ; ++i )
            temp_array[i] = nums[i];

        sort(temp_array.begin() , temp_array.end());
        for(int i = 0 ; i<n ; ++i){
            vector<int>::iterator itr = std::find(temp_array.begin(), temp_array.end(), nums[i]);
            if(itr != temp_array.cend()){
               int d = std::distance(temp_array.begin(), itr);
               ans.push_back(d);
            }
        }
        //cout<<endl;
        return ans ;
    }
};