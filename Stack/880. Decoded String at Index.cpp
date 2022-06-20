/*
https://leetcode.com/problems/decoded-string-at-index/
*/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
       long long int total = 0 ;
       for(auto it : s ){
           if(isdigit(it)){
               total = total*(it-'0');
           }
           else
               total = total + 1LL;
       }

       string ans = "";
       int n = s.length()-1;

       for(int i = n ; i>=0 ; --i ){
           k = k%total;
           if(k==0 && !isdigit(s[i])){
               ans = ans + s[i];
               return ans;
           }
           if(isdigit(s[i])){
               total = total / (s[i]-'0');
           }
           else{
               total = total - 1LL;
           }
       }
      return "";
    }
};