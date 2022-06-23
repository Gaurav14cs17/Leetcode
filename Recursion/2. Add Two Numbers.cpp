/*

https://leetcode.com/problems/add-two-numbers/

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

void solve(ListNode* root1 , ListNode*root2 ,int rem ,  ListNode*root ){
    if( root1==NULL || root2 == NULL ){
        if(root1 && root2== NULL){
            int x = root1->val + rem;
            ListNode *temp = new ListNode(x%10);
            root->next = temp;
            root = temp;
            solve(root1->next , root2 , x/10 , root );
        }
        else if(root2 && root1== NULL){
            int x = root2->val + rem;
            ListNode *temp = new ListNode(x%10);
            root->next = temp;
            root = temp;
            solve(root1 , root2->next , x/10 , root );
        }
        else if( rem && root1 == NULL && root2== NULL){
            ListNode *temp = new ListNode(rem);
            root->next = temp;
            root = temp;
            cout<<rem<<" ";
            solve(root1 , root2 , rem/10 , root );
        }
        else
            return ;
    }

    if(root1 && root2 ){
        int x = root1->val;
        int y = root2->val;
        int t = x +  y + rem ;

        ListNode *temp = new ListNode(t%10);
        root->next = temp;
        root = temp;
        solve(root1->next , root2->next , t/10 , root );
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *temp = new ListNode(0);
      ListNode *root = temp;
      solve( l1 , l2 , 0 , temp );
      return root->next;
    }
};