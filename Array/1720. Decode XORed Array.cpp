/*

https://leetcode.com/problems/decode-xored-array/
*/

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        int f = first;

        ans.push_back(f);
        for(int i = 0 ; i<encoded.size() ;++i ){
            int x = f ^ encoded[i];
            ans.push_back(x);
            f = x;
        }
        return ans;
    }
};