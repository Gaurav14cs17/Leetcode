/*
https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
*/

class Solution {
public:

    vector<string> split(string phrase, string delimiter){
        vector<string> list;
        string s = phrase;
        size_t pos = 0;
        string token;
        while ((pos = s.find(delimiter)) != string::npos) {
            token = s.substr(0, pos);
            list.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        list.push_back(s);
        return list;
    }

    int mostWordsFound(vector<string>& sentences) {
        int mx = -1;
        for(auto sent : sentences ){
            vector<string>ans = split(sent , " ");
            int len = ans.size();
            mx = max(mx , len);
        }
        return mx;

    }
};