/*

https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<int>pre(n+1);
        vector<int>suff(n+1);
        vector<bool>ans(n);

        pre[0] = candies[0];
        for(int i = 1  ; i<n ; ++i )pre[i] =max(pre[i-1] ,candies[i] );

        suff[n-1] = candies[n-1];
        for(int i = n-2  ; i>=0 ; --i )suff[i] =max(suff[i+1] ,candies[i] );

        for(int i = 0  ; i<n ; ++i ){
            int mx_val;
            if(i==0)
                mx_val = max(pre[0] , suff[i+1]);
            else if ( i == n-1)
                mx_val = max(pre[i-1] , suff[n-1]);
            else
                mx_val =  max(pre[i-1] , suff[i+1]);

            if((candies[i] + extraCandies ) >= mx_val )
                ans[i] = true;
            else
                ans[i] = false;
        }
        return ans ;
    }
};