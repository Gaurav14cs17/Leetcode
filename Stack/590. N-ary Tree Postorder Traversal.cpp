/*

https://leetcode.com/problems/n-ary-tree-postorder-traversal/

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/



void dfs( Node* root , vector<int>&root_val ){
    if(!root) return ;

    for( auto it : root->children )
        dfs(it , root_val);

    root_val.push_back(root->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
         dfs(root, ans);
        return ans;
    }
};