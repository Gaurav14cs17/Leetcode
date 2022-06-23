/*
https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
*/

char solve( int n , int k ){
    if(n==1 and  k==1 )
        return '0';

    int half = (1<<n)-1;
    half = half / 2 + 1;

    if(half == k )
        return '1';

    if( half > k ){
        return solve( n-1 , k );
    }

    if(solve(n-1 , (2*half - k ))=='0')
        return '1';
    else
        return '0';
}

class Solution {
public:
    char findKthBit(int n, int k) {
       return solve(n , k );
    }
};