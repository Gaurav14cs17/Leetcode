/*

https://leetcode.com/problems/daily-temperatures/

*/


''' Priority_Queue '''

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        priority_queue<pair<int , int >> pq ;
        pq.push({0 , temperatures[0]});
        for( int i = 1 ; i< n ; ++i ){
            while(!pq.empty() && temperatures[i] > pq.top().second ){
                auto it = pq.top();
                ans[it.first] = i - it.first;
                pq.pop();
            }
            pq.push({i , temperatures[i]});
        }
        return ans ;
    }
};



''' Stack '''

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n);
        stack<pair<int, int >>st;
        for( int i = 0  ; i<n ; ++i ){
            while(!st.empty() && temperatures[i]  >  st.top().second ){
                auto it = st.top();
                ans[it.first] = i-it.first;
                st.pop();
            }
            st.push({i, temperatures[i]});
        }
        while(!st.empty()){
            auto it = st.top();
            ans[it.first] = 0;
            st.pop();
        }
        return ans;
    }
};