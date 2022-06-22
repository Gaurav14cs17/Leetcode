/*

https://leetcode.com/problems/merge-two-sorted-lists/
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


void solve(ListNode* list1, ListNode* list2 , ListNode* root ){

      if(list1 == NULL || list2 == NULL ){
          if(list1 == NULL && list2 != NULL ){
              ListNode* temp = new ListNode(list2->val);
              root->next = temp;
              root = root->next;
              solve(list1 , list2->next , root);
          }

          else if(list1 != NULL && list2 == NULL ){
              ListNode* temp = new ListNode(list1->val);
              root->next = temp;
              root = root->next;
              solve(list1->next , list2 , root);
          }
          else
              return ;
      }


     else if(list1->val < list2->val  ){
          ListNode* temp = new ListNode(list1->val);
          root->next = temp;
          root = root->next;
          solve(list1->next , list2 , root);

      }
      else if(list1->val > list2->val ){
          ListNode* temp = new ListNode(list2->val);
          root->next = temp;
          root = root->next;
          solve(list1 , list2->next , root);

      }
    else{

          ListNode* temp = new ListNode(list2->val);
          root->next = temp;
          root = root->next;


          temp = new ListNode(list1->val);
          root->next = temp;
          root = root->next;


          solve(list1->next , list2->next , root);
    }


}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 && list2== NULL )
            return list1;

        if(list2 && list1== NULL )
            return list2;


        ListNode *root1 = new ListNode();
        ListNode *root = root1;
        solve(list1 , list2 , root1);
        return root->next;
    }
};