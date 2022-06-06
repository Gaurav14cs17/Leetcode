/*

https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
*/

class Solution {
public:
    vector<int> sumZero(int n) {
         vector<int>ans1;
         vector<int>ans;

        int cnt = n/2;
        while(cnt){
            ans1.push_back(cnt);
            cnt = cnt-1;
        }

        for(auto it : ans1){
            ans.push_back(-it);
            ans.push_back(it);
        }

        if(n&1)
            ans.push_back(0);


        return ans;
    }
};