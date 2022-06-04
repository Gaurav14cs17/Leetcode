
/*

https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

*/



class Solution {
public:
    bool check(string s ){
        int start = 0;
        int n = s.length();
        int end = n-1;
        while(start < n && end >=0 && start != end  ){
            if(s[start]==s[end]){
                start += 1;
                end   -= 1;

            }
            else
                return false;

        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(auto it : words){
            if(check(it)){
                ans = it;
                //cout<<ans<<" ";
                break ;
            }
        }
        return ans ;
    }
};