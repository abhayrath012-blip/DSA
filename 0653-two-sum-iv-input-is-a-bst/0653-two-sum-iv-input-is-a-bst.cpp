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
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int low=0,high=ans.size()-1;
        while(low<high){
            if(ans[low]+ans[high]==k) return true;
            else if(ans[low]+ans[high]>k) high--;
            else low++;
        }
        return false;

        
    }
    void inorder(TreeNode* node,vector<int>& ans){
        if(node==NULL) return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
};