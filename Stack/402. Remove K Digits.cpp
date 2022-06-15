/*

https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        int total_size = n-k;
        string s1 = "";


        stack<char>st;
        for( int i = 0  ; i<n ; ++i ){
            while(!st.empty() && (((n - i) + st.size()) > total_size) && nums[i]< st.top()){
                st.pop();
            }
            st.push(nums[i]);
        }

        while(!st.empty()){
            s1 = st.top() + s1;
            st.pop();
        }

        string s = "";
        int i=0;
        for(; i<total_size ; i++){
            if(s1[i] == '0')continue;
            else break;
        }

        for( ; i<total_size ; i++){
            s += s1[i];
        }

         if(s.empty())return "0";

        return s;
    }
};