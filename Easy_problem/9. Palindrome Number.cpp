/*

https://leetcode.com/problems/palindrome-number/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s = to_string(x);
        int i = 0;
        int e = s.length()-1;
        while(i < e ){
            if(s[i]==s[e]){
                ++i;
                --e;
            }
            else
                return false;
        }

        return true;
    }
};