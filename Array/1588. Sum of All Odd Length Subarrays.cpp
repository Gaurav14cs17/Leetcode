/*
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
*/

class Solution {
public:

    int sub_array_sum(vector<int>&arr , int s_idx , int e_idx){
        int sum = 0;
        for(int i = s_idx ; i<e_idx ; ++i )
            sum += arr[i];
        return sum;
    }


    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int window = 1 ; window<=n ; window = window + 2 ){
            for(int j = 0  ; j < (n-window+1) ; j = j + 1 ){
                int temp_sum = sub_array_sum(arr , j , (j+window));
                ans += temp_sum;
            }


        }
        return ans;

    }
};