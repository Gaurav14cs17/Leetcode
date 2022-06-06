/*
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int n = arr.size();
       vector<int>suff(n);
       suff[n-1] = -1;

        for( int i = n-2 ; i>=0 ; i--){
            suff[i] = max(suff[i+1] , arr[i+1] );
        }

        return suff;

    }
};