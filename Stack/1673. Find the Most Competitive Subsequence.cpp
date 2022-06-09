/*

https://leetcode.com/problems/find-the-most-competitive-subsequence/
*/


''' priority_queue ''


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<pair<int , int >, vector<pair<int , int >> ,greater<pair<int ,int>>>pq;

        for( int idx =  0 ; idx<=(n-k) ; idx++){
            pq.push({nums[idx] , idx });
        }

        auto it = pq.top();
        pq.pop();


        vector<int>ans;
        ans.push_back(it.first);

        int minIDX = it.second;

        for( int i = n-k+1 ;  i <n ;  ++i ){

            pq.push({nums[i] , i});
            auto it = pq.top();

            while(it.second < minIDX ){
               pq.pop();
               it = pq.top();
            }

            pq.pop();
            ans.push_back(it.first);
            minIDX = it.second;




        }

        return ans ;


    }
};



