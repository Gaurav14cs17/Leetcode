/*
https://leetcode.com/problems/count-items-matching-a-rule/
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for(auto s : items ){
            vector<string>s1;
            for(auto it : s)
                s1.push_back(it);

            if(ruleKey == "type" and ruleValue == s1[0] ) ++ans;
            if(ruleKey == "color" and ruleValue == s1[1] ) ++ans;
            if(ruleKey == "name" and ruleValue == s1[2] ) ++ans;

        }
        return ans;
    }
};