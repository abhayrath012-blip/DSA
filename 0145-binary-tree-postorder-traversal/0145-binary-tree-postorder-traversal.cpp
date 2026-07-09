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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* cur=root;
        TreeNode* prev=NULL;
        while(cur){
            if(cur->right==NULL){
                ans.push_back(cur->val);
                cur=cur->left;
            }
            else{
                prev=cur->right;
                while(prev->left&&prev->left!=cur){
                    prev=prev->left;
                }
                if(prev->left==NULL){
                    prev->left=cur;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
                else{
                    prev->left=NULL;
                    cur=cur->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        

        
    }
};