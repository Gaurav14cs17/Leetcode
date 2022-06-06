/*
https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/
*/

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int cnt = 0 ;
        int  n = startTime.size();

        for(int i = 0  ; i<n ; ++i ){
            if(startTime[i]<= queryTime && queryTime <= endTime[i])
                cnt += 1;
        }
        return cnt;
    }
};