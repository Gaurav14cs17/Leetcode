/*
https://leetcode.com/problems/reverse-linked-list/
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

    ListNode* solve(ListNode* curr_node , ListNode* prev_node = NULL){
        if(curr_node== NULL || curr_node->next == NULL )
            return curr_node ;

        ListNode* root = solve( curr_node->next , curr_node );

        ListNode*temp = curr_node->next;
        temp->next = curr_node;
        curr_node->next = NULL;

        return root;
    }

public:
    ListNode* reverseList(ListNode* head) {
        head = solve( head );
        // while(head){
        //     cout<<head->val<<" ";
        //     head = head->next;
        // }
        return head;
    }
};