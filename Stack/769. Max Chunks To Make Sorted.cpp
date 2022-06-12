
/*




https://leetcode.com/problems/max-chunks-to-make-sorted/



*/

//Backtracking

class Solution {
public:

    vector<int>br;
    int ans = 1;

    bool check(vector<int> temp,int p){
        sort(temp.begin(),temp.end());
        int i=p,j=0;
        while(i<br.size() && j<temp.size()){
            if(br[i]!=temp[j]) return false;
            ++i;
            ++j;
        }
        return true;
    }

    void Solve( vector<int>&arr , int start_idx ,int count, vector<int>temp ,int p_arry_idx  ){
        if(start_idx >= arr.size()){
            ans = max(ans , count);
            return;
        }

        for( int i = start_idx ; i < arr.size() ; ++i ){
             temp.push_back(arr[i]);
             if(check(temp , p_arry_idx )){
                 vector<int>v;
                 Solve(arr , i+1,count + 1 , v ,  p_arry_idx + temp.size() );
             }
        }
    }

    int maxChunksToSorted(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) br.push_back(i);
        vector<int> temp;
        Solve(arr,0,0,temp,0);
        return ans;
    }
};


// DP

class Solution {
public:

    int dp[100];

    int solve( vector<int>&arr , int s_idx , int n , int prev_val = INT_MIN ){

        if( s_idx >= n ) return 0;
        if(prev_val > *min_element(arr.begin() + s_idx , arr.end() ))
            return INT_MIN/2;

        int ans = INT_MIN/2;

        for( int i = s_idx ; i<n ; ++i ){
            int mx_val = *max_element(arr.begin() + s_idx , arr.begin() + i +  1 );
            int ret_mx_val =  1 + solve( arr , i + 1 , n , mx_val);
            ans = max( ans , ret_mx_val);
        }

        return dp[s_idx] = ans;
    }

    int maxChunksToSorted(vector<int>& arr) {
        memset(dp,-1,sizeof dp);
        return solve(arr,0,arr.size(),INT_MIN);
    }
};



// Matrix Chain Multiplication

class Solution {
public:
    bool check(vector<int>&arr , int start_idx , int mid ,int n ){
        int mx_value = *max_element(arr.begin() + start_idx , arr.begin() + mid +1 );
        int mn_value = *min_element(arr.begin() + mid +1 , arr.end());
        return mx_value <= mn_value;
    }

    int dp[100][100];
    int mcm(vector<int>&arr , int start_idx , int n  ){

        if(dp[start_idx][n] != -1 )
            return dp[start_idx][n];

        if( start_idx == n )
            return 1;

        int mx = 1;
        for( int k = start_idx ; k < n ; ++k ){
             if(check(arr ,  start_idx , k , n  )){
             int val = mcm( arr , start_idx , k ) + mcm( arr , k +1 , n );
             mx =  max( mx , val);
             }
        }
        return dp[start_idx][n] = mx;
    }

    int maxChunksToSorted(vector<int>& arr) {
        memset(dp,-1,sizeof dp);
        return mcm(arr , 0 , arr.size()-1);
    }
};





