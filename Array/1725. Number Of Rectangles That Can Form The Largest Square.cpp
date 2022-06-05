/*
https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/

*/


class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {

        map<int , int >mp;
        for(auto it : rectangles ){
           int mn = min(it[0] , it[1]);
           mp[mn] += 1;
        }
        int ans = -1 , local_mx = -1 ;

        for(auto it :  mp ){
           if(it.first > local_mx ){
               local_mx = it.first;
               ans = it.second;
           }
        }

        return ans ;
    }
};