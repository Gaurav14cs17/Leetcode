/*
https://leetcode.com/problems/shuffle-string/
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<char>temp_str(n);

        for(int i =0  ; i<n ; ++i){
           temp_str[indices[i]] = s[i];
        }


        string ans = "";
        for(auto it : temp_str)
            ans = ans + it;
        //cout<<ans<<endl;
        return ans;
    }
};