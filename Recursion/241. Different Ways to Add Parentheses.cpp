/*
https://leetcode.com/problems/different-ways-to-add-parentheses/
*/


vector<int> solve( string s , int start , int end ){

    if(start > end )
        return {};
    if((end - start)<=1){
        string num = s.substr(start , end + 1);
        return {stoi(num)};
    }

    vector<int>ans;

    for( int i = start ; i<=end ; ++i ){
        if(s[i]=='-' || s[i]=='+'|| s[i] == '*'){
            vector<int>left  = solve(s, start , i-1  );
            vector<int>right = solve(s , i+1 , end );
            for( auto l_it : left ){
                for( auto r_it : right ){
                    if(s[i]=='-'){
                        ans.push_back(l_it - r_it);
                    }
                    else if(s[i]=='+'){
                        ans.push_back(l_it + r_it);
                    }
                    else if(s[i]=='*'){
                        ans.push_back(l_it * r_it);
                    }
                }
            }
        }
    }
    return ans;
}


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length()-1;
        return solve( expression , 0 , n );
    }
};