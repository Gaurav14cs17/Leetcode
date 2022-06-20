/*
https://leetcode.com/problems/132-pattern/
*/


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack <pair<int,int>> st;
        vector<int> prefix(n, INT_MAX);


        int mini = INT_MAX;
        for(int i = 0; i<n; i++){
            prefix[i] = mini;
            mini = min(mini, nums[i]);
        }

        for( int i = 0  ; i<n ; ++i ){
            if(st.empty())st.push({nums[i] , i});
            else{
                while(!st.empty() && st.top().first <= nums[i])
                    st.pop();

                if(!st.empty() and prefix[st.top().second]<nums[i]) return true;

                st.push({nums[i],i});
            }
        }

        return false;
    }
};