/*

https://leetcode.com/problems/next-greater-node-in-linked-list/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<pair<int, int>>v;
        stack<pair<int,int>>st;
        int cnt = 0 ;

        while(head){
            int val = head->val;
            if(st.empty()){
                st.push({val,cnt++});
            }
            else{
                while(!st.empty() && st.top().first < val ){
                    v.push_back({st.top().second , val });
                    st.pop();
                }

                st.push({val, cnt++});
            }
           head = head->next;
        }
        while(!st.empty()){
            auto it = st.top();
            v.push_back({it.second , 0});
            st.pop();
        }
        sort(v.begin(), v.end());
        vector<int>ans(v.size());

        for(auto it : v){
            ans[it.first] = it.second;
        }

        return ans;
    }
};