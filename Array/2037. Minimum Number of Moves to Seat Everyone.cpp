/*
https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

*/


class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        sort(seats.begin() , seats.end());
        sort(students.begin() , students.end());
        int ans = 0 , n = seats.size() ;

        for(int i = 0 ; i<n ; ++i )
            ans += abs(seats[i]-students[i]);

        return ans;

    }
};