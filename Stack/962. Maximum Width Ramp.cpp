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


/*
segment tree
*/

const int N = 5e4+5;
int seg[4*N];


void update( int node , int l , int r , int idx , int val ){
    if( idx < l  || idx > r )
        return ;

    if(l==r){
        seg[node] = max(seg[node]  , val );
        return ;
    }

    int mid = ( l + r )>>1;
    update( node + node   , l , mid , idx , val);
    update( node + node + 1 , mid + 1, r , idx , val );
    seg[node] = max(seg[node+node] , seg[node+node+1]);

}

int query( int node , int l , int r , int ql , int qr ){
    if(qr < l || r < ql )return 0;
    if(ql<= l && r<= qr) return seg[node];
    int mid = (l + r )>>1;
    int left = query( node + node , l, mid , ql , qr);
    int right = query(node+node+1 , mid+1 , r , ql , qr);
    return max(left , right);
}


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ;
        memset(seg , 0 , sizeof seg);
        for( int i = n-1 ; i>=0 ; --i ){
            int idx = query( 1 , 0, N-1 , nums[i] , N-1);
            if(idx > i )
                ans = max(ans , idx - i);

            update( 1 , 0 , N -1 , nums[i] , i );
        }
        return ans;
    }
};


// Binary_search


int bs(vector<pair<int ,int >>&st , int val ){
    int left  = 0 ;
    int right = st.size()-1;
    while(left<right){
        int mid = (left + right)>>1;
        if(st[mid].first <  val ){
            right = mid;
        }
        else if( st[mid].first > val ){
            left = mid +1 ;
        }
        else{
            return st[mid].second;
        }
    }
    return st[left].second;
}



class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>>st;
        int n = nums.size();
        st.push_back({nums[0] , 0});
        int ans = 0 ;

        for( int i = 1 ; i<n ; ++i ){
            if(nums[i] >=st.back().first){
                int idx = bs(st , nums[i]);
                if( idx < i)
                    ans = max(ans , i-idx);
            }
            else{
                st.push_back({nums[i] , i});
            }
        }

        return ans;

    }
};