/*
1.1823. Find the Winner of the Circular Game
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

void solve(vector<int>&v, int s , int n ,  int k ){
    if(v.size()== 1)
        return ;

    s = ( s + k )%n;
    v.erase(v.begin() +  s);
    solve( v , s , n-1 , k );
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n);
        for(int i = 1 ; i<=n ; ++i )
            v[i-1] = i;
        solve( v , 0 , n , k-1);
        return v[0];
    }
};