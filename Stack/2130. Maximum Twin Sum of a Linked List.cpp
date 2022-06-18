/*
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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
    int pairSum(ListNode* head) {
        int n = 0 ;
        stack<int>st;
        while(head){
            st.push(head->val);
            head = head->next;
        }
        n = st.size()/2;
        stack<int>st2;
        while(n){
            st2.push(st.top());
            st.pop();
            --n;
        }

        int ans = 0;
        while(!st.empty() && !st2.empty()){
            ans = max(ans , st.top() + st2.top());
            st.pop();
            st2.pop();
        }
        return ans;
    }
};