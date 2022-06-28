/*
https://leetcode.com/problems/count-good-numbers/
*/



class Solution {
public:
    int mod = 1e9 + 7;
    long long pw(long long x, long long y) {
        if(y == 0)
            return 1;

       long long ans = pw(x, y>>1 );

        if(y%2 == 0 )
            return (ans * ans) % mod;

        else
            return (((ans * ans) % mod) * x) % mod;

    }
    int countGoodNumbers(long long n) {
        long long even , prime ;
        if(n&1){
            prime = n/2;
            even = n/2 + 1;
        }
        else{
            prime = n/2;
            even = n/2;
        }
        int number_of_prime = 4;
        int number_of_even = 5;

        int ans = (pw(number_of_even , even )%mod * pw(number_of_prime , prime )%mod)%mod;
        return ans;
    }
};