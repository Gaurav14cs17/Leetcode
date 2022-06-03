/*

https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0 ;
        for(auto it : operations ){

            if(it == "--X" or it=="X--")
                ans = ans -1;
            else
                ans = ans + 1;
        }
        return ans ;
    }
};