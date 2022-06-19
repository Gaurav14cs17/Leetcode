/*
https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
*/


class Solution {
public:
    int minDeletion(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        int ans = 0;
        for(auto it : nums ){
            if(st.empty()){
                st.push(it);
            }
            else{
                if(st.top() == it && st.size()%2 != 0 ){
                    continue;
                }
                else{
                    st.push(it);
                }
            }
        }
        //cout<<st.size();
        if(st.size()%2 != 0 ){
            return n - st.size()+1;
        }
        return n - st.size();
    }
};