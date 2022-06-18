/*
https://leetcode.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode* head) {
       vector<int>v;
       while(head){
           v.push_back(head->val);
           head = head->next;
       }
       int r = v.size()-1;
       int l = 0;

        while(l<r){
            if(v[l]==v[r] ){
                --r;
                ++l;
            }
            else
                break;

        }
        if(l==r && v[l]==v[r])
            return true;

        else if(r < l )
            return true;

        return false;
    }
};