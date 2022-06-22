/*
https://leetcode.com/problems/all-possible-full-binary-trees/
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

vector<TreeNode*> solve( int idx , int n ){
    if(n==idx){
       return  {new TreeNode(0)};
    }
    else if( idx > n )
        return {nullptr};

    vector<TreeNode*>ans;

    for( int k = idx + 1 ; k <= n ;  k = k + 2  ){
        vector<TreeNode*>left  = solve(idx , k-1);
        vector<TreeNode*>right = solve(k + 1 , n );
        for(auto l : left ){
            for(auto r : right ){
                TreeNode *root = new TreeNode(0);
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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1)){
            return {};
        }
        return solve(1, n );
    }
};