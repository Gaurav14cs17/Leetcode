
/*

https://leetcode.com/problems/number-of-digit-one/discuss/2215088/c%2B%2B-recursion-sol-with-diagram

*/

class Solution {
public:


    int dp[100][100][2];

    int solve(string &s , int level , int n , int total_cnt , bool up_limit  ){

        if(level == n )
            return total_cnt;

        if(dp[level][total_cnt][up_limit] != -1 )
            return dp[level][total_cnt][up_limit] ;

        int ans = 0 , limit = 9 ;
        if(up_limit)
            limit = s[level] - '0';

        int new_cnt =  0;
        for( int digit = 0  ; digit<=limit ; ++digit ){
            if(digit == 1)
                new_cnt = total_cnt + 1;
            else
                new_cnt = total_cnt;

            int t_up_limit  = (digit==limit) && up_limit ;
            ans = ans + solve( s , level + 1 , n , new_cnt , t_up_limit);

        }
        return dp[level][total_cnt][up_limit] = ans;
    }


    int countDigitOne(int n) {
        memset( dp , -1 , sizeof(dp));
        string s = to_string(n);
        int _n = s.length();

        return solve( s , 0 , _n , 0 , 1 );
    }
};