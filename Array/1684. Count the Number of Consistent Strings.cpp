/*

https://leetcode.com/problems/count-the-number-of-consistent-strings/

*/

class Solution {
public:

    bool check_map(map<char , int >&mp , string s ){
        for(auto s1 : s){
            if(mp.find(s1)==mp.end())
                return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char , int >mp;
        for(auto it : allowed)
            mp[it]+=1;

        int cnt = 0;
        int n = words.size();

        for(int i = 0  ; i<n ;++i ){
            if(check_map(mp, words[i]))
                cnt += 1;
        }

        return cnt;

    }
};