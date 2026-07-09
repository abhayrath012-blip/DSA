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
    bool getsum(TreeNode* root,int &targetSum,int sum){
        if(!root) return false;
        sum+=root->val;
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetSum) return true;
        }
        if(getsum(root->left,targetSum,sum)||getsum(root->right,targetSum,sum)) return true;
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        return getsum(root,targetSum,0);
        
    }
};