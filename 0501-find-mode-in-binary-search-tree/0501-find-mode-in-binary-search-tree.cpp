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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        vector<int> res;
        int cnt=1,prevcnt=0;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]) cnt++;
            else{
                if(cnt>prevcnt){
                    res.clear();
                    res.push_back(ans[i]);
                    prevcnt=cnt;
                }
                else if(cnt==prevcnt) res.push_back(ans[i]);
                cnt=1;
            }

        }
        if(cnt>prevcnt){
            res.clear();
            res.push_back(ans[ans.size()-1]);
            prevcnt=cnt;
        }
        else if(cnt==prevcnt) res.push_back(ans[ans.size()-1]);
        return res;

        
    }
    void helper(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans);
       
        
    }
};