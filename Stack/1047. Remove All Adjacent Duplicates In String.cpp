/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
    string removeDuplicates(string s) {

        stack<int>st;
        for(auto it : s ){
            if(st.empty() || it != st.top()){
                st.push(it);
            }
            else{

                while(!st.empty() and it == st.top()){
                    st.pop();
                }

            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};