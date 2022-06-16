/*
https://leetcode.com/problems/maximum-width-ramp/
*/

// DP

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int , int >>v;
        int n = nums.size();

        for( int i = 0  ; i<n ; ++i )
            v.push_back({nums[i] , i });

        sort(v.begin() , v.end());
        vector<int>dp1(n,0);
        vector<int>dp2(n,0);

        stack<int>st;
        for( int i = 0  ; i<n ; ++i ){
            if(i==0){
                dp1[i] = v[i].second;
                continue;
            }
            dp1[i] = min(dp1[i-1] , v[i].second);
        }


         for( int i = n-1  ; i>=0; --i ){
            if(i==n-1){
                dp2[i] = v[i].second;
                continue;
            }
            dp2[i] = max(dp2[i+1] , v[i].second);
        }

        vector<int>ans(n,0);
        for(int i = 0  ; i<n ;++i)
            ans[i] = abs(dp1[i]-dp2[i]);

        return *max_element(ans.begin(), ans.end());
    }
};

// stack + sorting



class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int , int >>v;
        int n = nums.size();

        for( int i = 0  ; i<n ; ++i )
            v.push_back({nums[i] , i });

        sort(v.begin() , v.end());
        int ans = -1;
        stack<int>st;

        for( int i = 0  ; i<n ; ++i ){
            if(st.empty()){
                st.push(v[i].second);
            }
            else{
                if(st.top()<v[i].second)
                        ans = max( ans , v[i].second - st.top());

                else
                    st.push(v[i].second);
            }
        }
        return ans;
    }
};


// monotonic stack

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        /*
          if index bassed : 1) 3-6  -> -3
                            2) 5-2  ->  3
        */
         for( int i = 0  ; i<n ; ++i ){
             if(st.empty())
                 st.push(i);
             else if (nums[i] < nums[st.top()])
                 st.push(i);
         }
         int ans = 0 ;
         for( int i = n-1 ; i>=0 ; --i ){
             while(!st.empty() && nums[i] >= nums[st.top()]){
                 ans =  max( ans , i - st.top());
                 st.pop();
             }
         }
       return ans;
    }
};