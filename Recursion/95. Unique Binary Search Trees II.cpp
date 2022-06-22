/*
https://leetcode.com/problems/unique-binary-search-trees-ii/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

vector<TreeNode*> solve( int start , int end ){
   if(start > end )
       return { NULL };

    vector<TreeNode*>ans;

   for( int i = start ; i <=end ; ++i ){
       vector<TreeNode*>left_tree = solve(start , i-1);
       vector<TreeNode*>right_tree = solve(i+1 , end );

       for(auto l : left_tree ){
           for(auto r : right_tree ){
               TreeNode *root  =  new TreeNode(i);
               root->left = l;
               root->right = r;
               ans.push_back(root);
           }
       }

   }
   return ans;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return solve(1 , n );
    }
};