/*
https://leetcode.com/problems/next-greater-element-ii/
*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
       map<int , int >mp;
       vector<int>ans(2*n);

       vector<int>temp = nums;

       for( int i = 0 ; i<n ; ++i )
           temp.push_back(nums[i]);

       stack<pair<int , int >>st;

        for( int i = 0  ; i<2*n ; ++i ){
            if(st.empty()){
                st.push({i , temp[i]});
            }
            else{

                while(!st.empty() && temp[i] > st.top().second){
                    auto it = st.top();
                    ans[it.first] = temp[i];
                    mp[it.second] = temp[i];
                    st.pop();
                }
                st.push({i , temp[i]});
            }
        }

        while(!st.empty()){
            auto it = st.top();
            if( mp.find(it.second) != mp.end())
                ans[it.first] = mp[it.second];
            else
                ans[it.first] = -1;


            st.pop();
        }
        vector<int>ans1;
        for( int i = 0  ; i<n ; ++i)
            ans1.push_back(ans[i]);
        return ans1;

    }
};