/*
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
*/


class Solution {
public:



    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto it :  nums ){
            int n = it;
            int temp_cnt = 0 ;
            while(n){
                temp_cnt +=1;
                n = n/10;
            }
            cnt += (temp_cnt&1)?0:1;
        }
        return cnt;
    }
};