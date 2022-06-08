/*

https://leetcode.com/problems/next-greater-element-i/

*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        unordered_map<int , int >mp;

        int n = nums2.size();
        for(int i = n-1 ; i>=0 ; --i){
            if(st.empty()){
                st.push(nums2[i]);
                mp[nums2[i]] = -1;
            }
            else {

                while(!st.empty() && nums2[i]> st.top()){
                    st.pop();
                }
                if( !st.empty() && nums2[i]< st.top()){
                    mp[nums2[i]] = st.top();
                }
                else{
                    mp[nums2[i]] = -1;
                }
                st.push(nums2[i]);

            }
        }
        vector<int>ans;
        for(auto it : nums1){
            ans.push_back(mp[it]);
        }
        return ans ;
    }
};