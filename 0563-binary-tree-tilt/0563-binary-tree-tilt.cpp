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
    int findTilt(TreeNode* root) {
        int sum=0;
        helper(root,sum);
        return sum;
        
    }
    int helper(TreeNode* root,int &sum){
        if(root==NULL) return 0;
        int leftsum=helper(root->left,sum);
        int rightsum=helper(root->right,sum);
        sum+=abs(rightsum-leftsum);
        return root->val+leftsum+rightsum;
    }
};