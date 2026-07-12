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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        preorder1(root1,ans1);
        preorder2(root2,ans2);
        if(ans1.size()!=ans2.size()) return false;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i]) return false;
        }
        return true;
        
    }
    void preorder1(TreeNode* root,vector<int>& ans1){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL) ans1.push_back(root->val);
        preorder1(root->left,ans1);
        preorder1(root->right,ans1);
    }
    void preorder2(TreeNode* root,vector<int>& ans2){
        if(root==NULL) return;
        if(root->left==NULL&&root->right==NULL) ans2.push_back(root->val);
        preorder2(root->left,ans2);
        preorder2(root->right,ans2);
    }
};