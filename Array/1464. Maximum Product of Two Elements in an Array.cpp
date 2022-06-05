/*

https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_mx = -1  , s_mx = -1;


        for(auto it : nums ){
            if(f_mx <= it ){
                s_mx = f_mx;
                f_mx = it;
            }
            else if(s_mx <= it && s_mx <= f_mx ){
                s_mx = it;
            }
        }
        return (f_mx-1)*(s_mx-1);
    }
};