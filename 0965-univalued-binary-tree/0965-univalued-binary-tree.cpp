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
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int> st;
        helper(root,st);
        if(st.size()>1) return false;
        return true;
    



        
    }
    void helper(TreeNode* root,unordered_set<int>& st){
        if(root==NULL) return;
        st.insert(root->val);
        helper(root->left,st);
        helper(root->right,st);
    }
};