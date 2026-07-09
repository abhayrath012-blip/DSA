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
    bool isSymmetricHelp(TreeNode* cur1,TreeNode* cur2){
        if(cur1==NULL||cur2==NULL) return (cur1==cur2);
        return (cur1->val==cur2->val)&&isSymmetricHelp(cur1->left,cur2->right)&&isSymmetricHelp(cur1->right,cur2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricHelp(root->left,root->right);
        
    }
};