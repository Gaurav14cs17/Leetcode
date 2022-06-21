/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

// Memory Limit Exceeded


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char , int>>st;
        int n = s.length();
        k = k-1;

        for( int i = 0 ; i<n ; ++i ){
            if(st.empty())
                st.push({s[i],1});
            else{

                if(st.top().second%k ==0 && st.top().first == s[i] ){
                    int cnt = 1 ;
                    while(!st.empty() && (st.top().first == s[i]) && cnt <= k ){
                        st.pop();
                        cnt = cnt + 1;
                    }
                }
                else if(st.top().first == s[i]){
                    int nxt = st.top().second + 1;
                    st.push({s[i] , nxt });
                }
                else{
                    st.push({s[i], 1});
                }

            }
        }
      string ans = "";
      while(!st.empty()){

         // Memory Limit Exceeded
         // ans = ans + st.top().first;
         ans += st.top().first;
          st.pop();
      }
      reverse(ans.begin() , ans.end());
      return ans ;
    }
};